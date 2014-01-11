/*
 *  linux/arch/arm/plat-mxc/time.c
 *
 *  Copyright (C) 2000-2001 Deep Blue Solutions
 *  Copyright (C) 2002 Shane Nay (shane@minirl.com)
 *  Copyright (C) 2006-2007 Pavel Pisa (ppisa@pikron.com)
 *  Copyright (C) 2008 Juergen Beisert (kernel@pengutronix.de)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/clockchips.h>
#include <linux/clk.h>
#include <linux/ipipe.h>

#include <mach/hardware.h>
#include <asm/sched_clock.h>
#include <asm/mach/time.h>
#include <mach/common.h>

/*
 * There are 2 versions of the timer hardware on Freescale MXC hardware.
 * Version 1: MX1/MXL, MX21, MX27.
 * Version 2: MX25, MX31, MX35, MX37, MX51
 */

/* defines common for all i.MX */
#define MXC_TCTL		0x00
#define MXC_TCTL_TEN		(1 << 0) /* Enable module */
#define MXC_TPRER		0x04

/* MX1, MX21, MX27 */
#define MX1_2_TCTL_CLK_PCLK1	(1 << 1)
#define MX1_2_TCTL_IRQEN	(1 << 4)
#define MX1_2_TCTL_FRR		(1 << 8)
#define MX1_2_TCMP		0x08
#define MX1_2_TCN		0x10
#define MX1_2_TSTAT		0x14

/* MX21, MX27 */
#define MX2_TSTAT_CAPT		(1 << 1)
#define MX2_TSTAT_COMP		(1 << 0)

/* MX31, MX35, MX25, MX5 */
#define V2_TCTL_WAITEN		(1 << 3) /* Wait enable mode */
#define V2_TCTL_CLK_IPG		(1 << 6)
#define V2_TCTL_CLK_PER		(2 << 6)
#define V2_TCTL_CLK_OSC_DIV8	 (5 << 6)
#define V2_TCTL_CLK_OSC		(7 << 6)
#define V2_TCTL_FRR			(1 << 9)
#define V2_TCTL_ENABLE24M	(1 << 10)
#define V2_TPRER_PRE24M_DIV8	7
#define V2_TPRER_PRE24M_MASK	0xF
#define V2_TPRER_PRE24M_OFFSET	12
#define V2_IR			0x0c
#define V2_TSTAT		0x08
#define V2_TSTAT_OF1		(1 << 0)
#define V2_TCN			0x24
#define V2_TCMP			0x10

#define timer_is_v1()	(cpu_is_mx1() || cpu_is_mx21() || cpu_is_mx27())
#define timer_is_v2()	(!timer_is_v1())

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
int __ipipe_mach_timerint;
EXPORT_SYMBOL(__ipipe_mach_timerint);

int __ipipe_mach_timerstolen = 0;
EXPORT_SYMBOL(__ipipe_mach_timerstolen);

unsigned int __ipipe_mach_ticks_per_jiffy = LATCH;
EXPORT_SYMBOL(__ipipe_mach_ticks_per_jiffy);

static unsigned mxc_min_delay;
#endif /* CONFIG_IPIPE && !CONFIG_SMP */

static struct clock_event_device clockevent_mxc;
static enum clock_event_mode clockevent_mode = CLOCK_EVT_MODE_UNUSED;

static void __iomem *timer_base;

static inline void gpt_irq_disable(void)
{
	unsigned int tmp;

	if (timer_is_v2())
		__raw_writel(0, timer_base + V2_IR);
	else {
		tmp = __raw_readl(timer_base + MXC_TCTL);
		__raw_writel(tmp & ~MX1_2_TCTL_IRQEN, timer_base + MXC_TCTL);
	}
}

static inline void gpt_irq_enable(void)
{
	if (timer_is_v2())
		__raw_writel(1<<0, timer_base + V2_IR);
	else {
		__raw_writel(__raw_readl(timer_base + MXC_TCTL) | MX1_2_TCTL_IRQEN,
			timer_base + MXC_TCTL);
	}
}

static void gpt_irq_acknowledge(void)
{
	if (timer_is_v1()) {
		if (cpu_is_mx1())
			__raw_writel(0, timer_base + MX1_2_TSTAT);
		else
			__raw_writel(MX2_TSTAT_CAPT | MX2_TSTAT_COMP,
				timer_base + MX1_2_TSTAT);
	} else if (timer_is_v2())
		__raw_writel(V2_TSTAT_OF1, timer_base + V2_TSTAT);
}

static void __iomem *sched_clock_reg;

static DEFINE_CLOCK_DATA(cd);
unsigned long long notrace sched_clock(void)
{
	cycle_t cyc = sched_clock_reg ? __raw_readl(sched_clock_reg) : 0;

	return cyc_to_sched_clock(&cd, cyc, (u32)~0);
}

static void notrace mxc_update_sched_clock(void)
{
	cycle_t cyc = sched_clock_reg ? __raw_readl(sched_clock_reg) : 0;
	update_sched_clock(&cd, cyc, (u32)~0);
}

static int __init mxc_clocksource_init(struct clk *timer_clk)
{
	unsigned int c = clk_get_rate(timer_clk);
	void __iomem *reg = timer_base + (timer_is_v2() ? V2_TCN : MX1_2_TCN);

	sched_clock_reg = reg;

	init_sched_clock(&cd, mxc_update_sched_clock, 32, c);
	return clocksource_mmio_init(reg, "mxc_timer1", c, 200, 32,
			clocksource_mmio_readl_up);
}

/* clock event */

static int mx1_2_set_next_event(unsigned long evt,
			      struct clock_event_device *unused)
{
	unsigned long tcmp;

	tcmp = __raw_readl(timer_base + MX1_2_TCN) + evt;

	__raw_writel(tcmp, timer_base + MX1_2_TCMP);

	return (int)(tcmp - __raw_readl(timer_base + MX1_2_TCN)) < 0 ?
				-ETIME : 0;
}

static int v2_set_next_event(unsigned long evt,
			      struct clock_event_device *unused)
{
	unsigned long tcmp;

	tcmp = __raw_readl(timer_base + V2_TCN) + evt;

	__raw_writel(tcmp, timer_base + V2_TCMP);

	return 0;
}

#ifdef DEBUG
static const char *clock_event_mode_label[] = {
	[CLOCK_EVT_MODE_PERIODIC] = "CLOCK_EVT_MODE_PERIODIC",
	[CLOCK_EVT_MODE_ONESHOT]  = "CLOCK_EVT_MODE_ONESHOT",
	[CLOCK_EVT_MODE_SHUTDOWN] = "CLOCK_EVT_MODE_SHUTDOWN",
	[CLOCK_EVT_MODE_UNUSED]   = "CLOCK_EVT_MODE_UNUSED"
};
#endif /* DEBUG */

static void mxc_set_mode(enum clock_event_mode mode,
				struct clock_event_device *evt)
{
	unsigned long flags;

	/*
	 * The timer interrupt generation is disabled at least
	 * for enough time to call mxc_set_next_event()
	 */
	local_irq_save(flags);

	/* Disable interrupt in GPT module */
	gpt_irq_disable();

	if (mode != clockevent_mode) {
		/* Set event time into far-far future */
		if (timer_is_v2())
			__raw_writel(__raw_readl(timer_base + V2_TCN) - 3,
					timer_base + V2_TCMP);
		else
			__raw_writel(__raw_readl(timer_base + MX1_2_TCN) - 3,
					timer_base + MX1_2_TCMP);

		/* Clear pending interrupt */
		gpt_irq_acknowledge();
	}

#ifdef DEBUG
	printk(KERN_INFO "mxc_set_mode: changing mode from %s to %s\n",
		clock_event_mode_label[clockevent_mode],
		clock_event_mode_label[mode]);
#endif /* DEBUG */

	/* Remember timer mode */
	clockevent_mode = mode;
	local_irq_restore(flags);

	switch (mode) {
	case CLOCK_EVT_MODE_PERIODIC:
		printk(KERN_ERR"mxc_set_mode: Periodic mode is not "
				"supported for i.MX\n");
		break;
	case CLOCK_EVT_MODE_ONESHOT:
	/*
	 * Do not put overhead of interrupt enable/disable into
	 * mxc_set_next_event(), the core has about 4 minutes
	 * to call mxc_set_next_event() or shutdown clock after
	 * mode switching
	 */
		local_irq_save(flags);
		gpt_irq_enable();
		local_irq_restore(flags);
		break;
	case CLOCK_EVT_MODE_SHUTDOWN:
	case CLOCK_EVT_MODE_UNUSED:
	case CLOCK_EVT_MODE_RESUME:
		/* Left event sources disabled, no more interrupts appear */
		break;
	}
}

/*
 * IRQ handler for the timer
 */
static irqreturn_t mxc_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &clockevent_mxc;
#if !defined(CONFIG_IPIPE) || defined(CONFIG_SMP)
	uint32_t tstat;

	if (timer_is_v2())
		tstat = __raw_readl(timer_base + V2_TSTAT);
	else
		tstat = __raw_readl(timer_base + MX1_2_TSTAT);

	gpt_irq_acknowledge();
#else /* CONFIG_IPIPE && !CONFIG_SMP */
	__ipipe_tsc_update();
#endif /* CONFIG_IPIPE && !CONFIG_SMP */

	evt->event_handler(evt);

	return IRQ_HANDLED;
}

static struct irqaction mxc_timer_irq = {
	.name		= "i.MX Timer Tick",
	.flags		= IRQF_DISABLED | IRQF_TIMER | IRQF_IRQPOLL,
	.handler	= mxc_timer_interrupt,
};

static struct clock_event_device clockevent_mxc = {
	.name		= "mxc_timer1",
	.features	= CLOCK_EVT_FEAT_ONESHOT,
	.shift		= 32,
	.set_mode	= mxc_set_mode,
	.set_next_event	= mx1_2_set_next_event,
	.rating		= 200,
};

static int __init mxc_clockevent_init(struct clk *timer_clk)
{
	unsigned int c = clk_get_rate(timer_clk);

	if (timer_is_v2())
		clockevent_mxc.set_next_event = v2_set_next_event;

	clockevent_mxc.mult = div_sc(c, NSEC_PER_SEC,
					clockevent_mxc.shift);
	clockevent_mxc.max_delta_ns =
			clockevent_delta2ns(0xfffffffe, &clockevent_mxc);
	clockevent_mxc.min_delta_ns =
			clockevent_delta2ns(0xff, &clockevent_mxc);

	clockevent_mxc.cpumask = cpumask_of(0);

	clockevents_register_device(&clockevent_mxc);

	return 0;
}

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
static struct __ipipe_tscinfo tsc_info = {
	.type = IPIPE_TSC_TYPE_FREERUNNING,
	.u = {
		{
			.mask = 0xffffffff,
		},
	},
};

int __ipipe_check_tickdev(const char *devname)
{
	return !strcmp(devname, clockevent_mxc.name);
}

void __ipipe_mach_acktimer(void)
{
	uint32_t tstat;

	if (timer_is_v2())
		tstat = __raw_readl(timer_base + V2_TSTAT);
	else
		tstat = __raw_readl(timer_base + MX1_2_TSTAT);

	gpt_irq_acknowledge();
}
/*
 * Reprogram the timer
 */

void __ipipe_mach_set_dec(unsigned long delay)
{
	if (delay <= mxc_min_delay
	    || (!timer_is_v2() && mx1_2_set_next_event(delay, NULL) < 0)
	    || (timer_is_v2() && v2_set_next_event(delay, NULL) < 0))
		ipipe_trigger_irq(__ipipe_mach_timerint);
}
EXPORT_SYMBOL(__ipipe_mach_set_dec);

void __ipipe_mach_release_timer(void)
{
	mxc_set_mode(clockevent_mxc.mode, &clockevent_mxc);
	if (clockevent_mxc.mode == CLOCK_EVT_MODE_ONESHOT)
		clockevent_mxc.set_next_event(LATCH, &clockevent_mxc);
}
EXPORT_SYMBOL(__ipipe_mach_release_timer);

unsigned long __ipipe_mach_get_dec(void)
{
	if (!timer_is_v2())
		return __raw_readl(timer_base + MX1_2_TCMP)
			- __raw_readl(timer_base + MX1_2_TCN);
	else
		return __raw_readl(timer_base + V2_TCMP)
			- __raw_readl(timer_base + V2_TCN);
}
#endif /* CONFIG_IPIPE && !CONFIG_SMP */

void __init
mxc_timer_init(struct clk *timer_clk,
	       void __iomem *base, unsigned long phys, int irq)
{
	uint32_t tctl_val;
	u32 reg;

	clk_enable(timer_clk);

	timer_base = base;

	/*
	 * Initialise to a known state (all timers off, and timing reset)
	 */

	__raw_writel(0, timer_base + MXC_TCTL);
	__raw_writel(0, timer_base + MXC_TPRER); /* see datasheet note */

	if (timer_is_v2()) {
		if (cpu_is_mx5() || cpu_is_mx6sl() ||
			mx6q_revision() == IMX_CHIP_REVISION_1_0)
			tctl_val = V2_TCTL_CLK_PER | V2_TCTL_FRR |
						V2_TCTL_WAITEN | MXC_TCTL_TEN;
		else {
			tctl_val = V2_TCTL_CLK_OSC_DIV8 | V2_TCTL_FRR |
						V2_TCTL_WAITEN | MXC_TCTL_TEN;
			if (!cpu_is_mx6q()) {
				reg = __raw_readl(timer_base + MXC_TPRER);
				reg |= (V2_TPRER_PRE24M_DIV8 <<
							V2_TPRER_PRE24M_OFFSET);
				__raw_writel(reg, timer_base + MXC_TPRER);
				/* Enable the 24MHz input clock. */
				tctl_val |= V2_TCTL_ENABLE24M;
			}
		}
	} else
		tctl_val = MX1_2_TCTL_FRR | MX1_2_TCTL_CLK_PCLK1 | MXC_TCTL_TEN;

	__raw_writel(tctl_val, timer_base + MXC_TCTL);

	/* init and register the timer to the framework */
	mxc_clocksource_init(timer_clk);
	mxc_clockevent_init(timer_clk);

	/* Make irqs happen */
	setup_irq(irq, &mxc_timer_irq);

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
	__ipipe_mach_timerint = irq;
	__ipipe_mach_ticks_per_jiffy = (clk_get_rate(timer_clk) + HZ / 2) / HZ;
	tsc_info.freq = clk_get_rate(timer_clk);
	mxc_min_delay = 2 * ((__ipipe_cpu_freq + 500000) / 1000000) ?: 1;

	if (timer_is_v1()) {
		tsc_info.u.counter_paddr = phys + MX1_2_TCN;
		tsc_info.counter_vaddr =(unsigned long)(timer_base + MX1_2_TCN);
	} else {
		tsc_info.u.counter_paddr = phys + V2_TCN;
		tsc_info.counter_vaddr = (unsigned long)(timer_base + V2_TCN);
	}
	__ipipe_tsc_register(&tsc_info);
#endif /* CONFIG_IPIPE && !CONFIG_SMP */
}
