/*
 * linux/arch/arm/mach-omap2/timer-gp.c
 *
 * OMAP2 GP timer support.
 *
 * Copyright (C) 2009 Nokia Corporation
 *
 * Update to use new clocksource/clockevent layers
 * Author: Kevin Hilman, MontaVista Software, Inc. <source@mvista.com>
 * Copyright (C) 2007 MontaVista Software, Inc.
 *
 * Original driver:
 * Copyright (C) 2005 Nokia Corporation
 * Author: Paul Mundt <paul.mundt@nokia.com>
 *         Juha Yrjölä <juha.yrjola@nokia.com>
 * OMAP Dual-mode timer framework support by Timo Teras
 *
 * Some parts based off of TI's 24xx code:
 *
 * Copyright (C) 2004-2009 Texas Instruments, Inc.
 *
 * Roughly modelled after the OMAP1 MPU timer code.
 * Added OMAP4 support - Santosh Shilimkar <santosh.shilimkar@ti.com>
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file "COPYING" in the main directory of this archive
 * for more details.
 */
#include <linux/init.h>
#include <linux/time.h>
#include <linux/interrupt.h>
#include <linux/err.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/irq.h>
#include <linux/clocksource.h>
#include <linux/clockchips.h>
#include <linux/ipipe.h>

#include <asm/mach/time.h>
#include <plat/dmtimer.h>
#include <asm/localtimer.h>
#include <asm/sched_clock.h>
#include <plat/common.h>
#include <plat/omap_hwmod.h>

#include "timer-gp.h"


/* MAX_GPTIMER_ID: number of GPTIMERs on the chip */
#define MAX_GPTIMER_ID		12

static struct omap_dm_timer *gptimer;
static struct clock_event_device clockevent_gpt;
static u8 __initdata gptimer_id = 1;
static u8 __initdata inited;
struct omap_dm_timer *gptimer_wakeup;
#ifndef CONFIG_OMAP_32K_TIMER
static struct omap_dm_timer *gpt_clocksource;
#endif /* !CONFIG_OMAP_32K_TIMER */

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
int __ipipe_mach_timerint;
EXPORT_SYMBOL(__ipipe_mach_timerint);

unsigned int __ipipe_mach_ticks_per_jiffy;
EXPORT_SYMBOL(__ipipe_mach_ticks_per_jiffy);

int __ipipe_mach_timerstolen;
EXPORT_SYMBOL(__ipipe_mach_timerstolen);
#endif /* CONFIG_IPIPE && !CONFIG_SMP */

static irqreturn_t omap2_gp_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &clockevent_gpt;
#if !defined(CONFIG_IPIPE) || defined(CONFIG_SMP)
	struct omap_dm_timer *gpt = (struct omap_dm_timer *)dev_id;

	omap_dm_timer_write_status(gpt, OMAP_TIMER_INT_OVERFLOW);
#else /* CONFIG_IPIPE */
	__ipipe_tsc_update();
#endif /* CONFIG_IPIPE */

	evt->event_handler(evt);
	return IRQ_HANDLED;
}

static struct irqaction omap2_gp_timer_irq = {
	.name		= "gp timer",
	.flags		= IRQF_DISABLED | IRQF_TIMER | IRQF_IRQPOLL,
	.handler	= omap2_gp_timer_interrupt,
};

static int omap2_gp_timer_set_next_event(unsigned long cycles,
					 struct clock_event_device *evt)
{
	omap_dm_timer_set_load_start(gptimer, 0, 0xffffffff - cycles);

	return 0;
}

static void omap2_gp_timer_set_mode(enum clock_event_mode mode,
				    struct clock_event_device *evt)
{
	u32 period;

	omap_dm_timer_stop(gptimer);

	switch (mode) {
	case CLOCK_EVT_MODE_PERIODIC:
		period = clk_get_rate(omap_dm_timer_get_fclk(gptimer)) / HZ;
		period -= 1;
		omap_dm_timer_set_load_start(gptimer, 1, 0xffffffff - period);
		break;
	case CLOCK_EVT_MODE_ONESHOT:
		break;
	case CLOCK_EVT_MODE_UNUSED:
	case CLOCK_EVT_MODE_SHUTDOWN:
	case CLOCK_EVT_MODE_RESUME:
		break;
	}
}

static struct clock_event_device clockevent_gpt = {
	.name		= "gp timer",
	.features       = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT,
	.shift		= 32,
	.set_next_event	= omap2_gp_timer_set_next_event,
	.set_mode	= omap2_gp_timer_set_mode,
};

/**
 * omap2_gp_clockevent_set_gptimer - set which GPTIMER is used for clockevents
 * @id: GPTIMER to use (1..MAX_GPTIMER_ID)
 *
 * Define the GPTIMER that the system should use for the tick timer.
 * Meant to be called from board-*.c files in the event that GPTIMER1, the
 * default, is unsuitable.  Returns -EINVAL on error or 0 on success.
 */
int __init omap2_gp_clockevent_set_gptimer(u8 id)
{
	if (id < 1 || id > MAX_GPTIMER_ID)
		return -EINVAL;

	BUG_ON(inited);

	gptimer_id = id;

	return 0;
}

#ifdef CONFIG_IPIPE
static struct __ipipe_tscinfo __maybe_unused tsc_info = {
	.type = IPIPE_TSC_TYPE_FREERUNNING,
	.u = {
		{
			.mask = 0xffffffff,
		},
	},
};

#ifndef CONFIG_SMP
int __ipipe_check_tickdev(const char *devname)
{
	return !strcmp(devname, clockevent_gpt.name);
}
#endif /* !CONFIG_SMP */
#endif /* CONFIG_IPIPE */

static void __init omap2_gp_clockevent_init(void)
{
	u32 tick_rate;
	int src;
	char clockevent_hwmod_name[8]; /* 8 = sizeof("timerXX0") */

	inited = 1;

	sprintf(clockevent_hwmod_name, "timer%d", gptimer_id);
	omap_hwmod_setup_one(clockevent_hwmod_name);

	gptimer = omap_dm_timer_request_specific_nonposted(gptimer_id);
	BUG_ON(gptimer == NULL);
	gptimer_wakeup = gptimer;

#if defined(CONFIG_OMAP_32K_TIMER)
	src = OMAP_TIMER_SRC_32_KHZ;
#else
	src = OMAP_TIMER_SRC_SYS_CLK;
	WARN(gptimer_id == 12, "WARNING: GPTIMER12 can only use the "
	     "secure 32KiHz clock source\n");
#endif

	if (gptimer_id != 12)
		WARN(IS_ERR_VALUE(omap_dm_timer_set_source(gptimer, src)),
		     "timer-gp: omap_dm_timer_set_source() failed\n");

	tick_rate = clk_get_rate(omap_dm_timer_get_fclk(gptimer));

	pr_info("OMAP clockevent source: GPTIMER%d at %u Hz\n",
		gptimer_id, tick_rate);

	omap2_gp_timer_irq.dev_id = (void *)gptimer;

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
	__ipipe_mach_timerint = omap_dm_timer_get_irq(gptimer);
	__ipipe_mach_ticks_per_jiffy = (tick_rate + HZ / 2) / HZ;
#endif /* CONFIG_IPIPE && !CONFIG_SMP*/

	setup_irq(omap_dm_timer_get_irq(gptimer), &omap2_gp_timer_irq);
	omap_dm_timer_set_int_enable(gptimer, OMAP_TIMER_INT_OVERFLOW);

	clockevent_gpt.mult = div_sc(tick_rate, NSEC_PER_SEC,
				     clockevent_gpt.shift);
	clockevent_gpt.max_delta_ns =
		clockevent_delta2ns(0xffffffff, &clockevent_gpt);
	clockevent_gpt.min_delta_ns =
		clockevent_delta2ns(3, &clockevent_gpt);
		/* Timer internal resynch latency. */
	clockevent_gpt.cpumask = cpumask_of(0);
	clockevents_register_device(&clockevent_gpt);
}

/* Clocksource code */

#ifdef CONFIG_OMAP_32K_TIMER
/*
 * When 32k-timer is enabled, don't use GPTimer for clocksource
 * instead, just leave default clocksource which uses the 32k
 * sync counter.  See clocksource setup in plat-omap/counter_32k.c
 */

static void __init omap2_gp_clocksource_init(void)
{
	omap_init_clocksource_32k();
}

#else
/*
 * clocksource
 */
static DEFINE_CLOCK_DATA(cd);
static struct omap_dm_timer *gpt_clocksource;
static cycle_t notrace clocksource_read_dummy(struct clocksource *cs)
{
       return 0;
}

static cycle_t notrace clocksource_read_cycles(struct clocksource *cs)
{
	return (cycle_t)omap_dm_timer_read_counter(gpt_clocksource);
}

static struct clocksource clocksource_gpt = {
	.name		= "gp timer",
	.rating		= 300,
	.read		= clocksource_read_dummy,
	.mask		= CLOCKSOURCE_MASK(32),
	.flags		= CLOCK_SOURCE_IS_CONTINUOUS,
};

unsigned long long notrace sched_clock(void)
{
       u32 cyc = clocksource_gpt.read(&clocksource_gpt);
       return cyc_to_sched_clock(&cd, cyc, (u32)~0);
}

static void notrace dmtimer_update_sched_clock(void)
{
	u32 cyc;

	cyc = omap_dm_timer_read_counter(gpt_clocksource);

	update_sched_clock(&cd, cyc, (u32)~0);
}

/* Setup free-running counter for clocksource */
static void __init omap2_gp_clocksource_init(void)
{
	static struct omap_dm_timer *gpt;
	u32 tick_rate;
	static char err1[] __initdata = KERN_ERR
		"%s: failed to request dm-timer\n";
	static char err2[] __initdata = KERN_ERR
		"%s: can't register clocksource!\n";
	char clocksource_hwmod_name[8]; /* 8 = sizeof("timerXX0") */


#if defined(CONFIG_IPIPE)
	if (cpu_is_omap34xx()) {
		sprintf(clocksource_hwmod_name, "timer%d", 3);
		omap_hwmod_setup_one(clocksource_hwmod_name);
		gpt = omap_dm_timer_request_specific(3);
	} else
#endif /* CONFIG_IPIPE */
		{
			sprintf(clocksource_hwmod_name, "timer%d", 2);
			omap_hwmod_setup_one(clocksource_hwmod_name);
			gpt = omap_dm_timer_request();
		}

	if (!gpt)
		printk(err1, clocksource_gpt.name);
	gpt_clocksource = gpt;

	omap_dm_timer_set_source(gpt, OMAP_TIMER_SRC_SYS_CLK);
	tick_rate = clk_get_rate(omap_dm_timer_get_fclk(gpt));

	omap_dm_timer_set_load_start(gpt, 1, 0);

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
	tsc_info.freq = tick_rate;
	tsc_info.counter_vaddr =
		omap_dm_timer_get_virt_counter_addr(gpt_clocksource);
	tsc_info.u.counter_paddr =
		omap_dm_timer_get_phys_counter_addr(gpt_clocksource);
	__ipipe_tsc_register(&tsc_info);
#endif

	if (clocksource_register_hz(&clocksource_gpt, tick_rate))
		printk(err2, clocksource_gpt.name);

	clocksource_gpt.read = &clocksource_read_cycles;
	init_sched_clock(&cd, dmtimer_update_sched_clock, 32, tick_rate);
}
#endif

static void __init omap2_gp_timer_init(void)
{
#ifdef CONFIG_LOCAL_TIMERS
	if (cpu_is_omap44xx()) {
		twd_base = ioremap(OMAP44XX_LOCAL_TWD_BASE, SZ_256);
		BUG_ON(!twd_base);
	}
#endif
	omap_dm_timer_init();

#ifdef CONFIG_IPIPE
	if (cpu_is_omap34xx())
		omap2_gp_clockevent_set_gptimer(2);
#endif
	omap2_gp_clockevent_init();
	omap2_gp_clocksource_init();
}

struct sys_timer omap_timer = {
	.init	= omap2_gp_timer_init,
};

#if defined(CONFIG_IPIPE) && !defined(CONFIG_SMP)
void __ipipe_mach_acktimer(void)
{
	omap_dm_timer_write_status(gptimer, OMAP_TIMER_INT_OVERFLOW);
	omap_dm_timer_read_status(gptimer);
}

/*
 * Reprogram the timer
 */

void __ipipe_mach_set_dec(unsigned long delay)
{
	if (delay > 3)
		omap_dm_timer_set_load_start(gptimer, 0, 0xffffffff - delay);
	else
		ipipe_trigger_irq(__ipipe_mach_timerint);
}
EXPORT_SYMBOL(__ipipe_mach_set_dec);

void __ipipe_mach_release_timer(void)
{
	struct clock_event_device *ckdev = &clockevent_gpt;
	ckdev->set_mode(ckdev->mode, ckdev);
	if (ckdev->mode == CLOCK_EVT_MODE_ONESHOT)
		ckdev->set_next_event(__ipipe_mach_ticks_per_jiffy, ckdev);
}
EXPORT_SYMBOL(__ipipe_mach_release_timer);

unsigned long __ipipe_mach_get_dec(void)
{
	return 0xffffffff - omap_dm_timer_read_counter(gptimer);
}
#endif /* CONFIG_IPIPE */
