/*
 *  linux/arch/arm/kernel/smp_twd.c
 *
 *  Copyright (C) 2002 ARM Ltd.
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/smp.h>
#include <linux/jiffies.h>
#include <linux/clockchips.h>
#include <linux/irq.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/cpufreq.h>
#include <linux/err.h>
#include <linux/ipipe.h>

#include <asm/smp_twd.h>
#include <asm/hardware/gic.h>

/* set up by the platform code */
void __iomem *twd_base;
static struct clk *twd_clk;

static unsigned long twd_timer_rate;

static struct clock_event_device __percpu **twd_evt;

#if defined(CONFIG_IPIPE) && defined(CONFIG_SMP)
void __iomem *gt_base;

unsigned __ipipe_twd_hrtimer_freq;

unsigned int __ipipe_mach_ticks_per_jiffy;
EXPORT_SYMBOL(__ipipe_mach_ticks_per_jiffy);

int __ipipe_mach_timerstolen;
EXPORT_SYMBOL(__ipipe_mach_timerstolen);

static DEFINE_PER_CPU(int, timer_mode) = {
	CLOCK_EVT_MODE_SHUTDOWN
};

void __ipipe_ack_localtimer(unsigned irq, struct irq_desc *desc)
{
	__raw_writel(1, twd_base + TWD_TIMER_INTSTAT);
}

asmlinkage void __ipipe_grab_localtimer(struct pt_regs *regs)
{
	__ipipe_grab_irq(__ipipe_mach_hrtimer_irq, regs);
}

void __ipipe_mach_set_dec(unsigned long delay)
{
	if (delay <= 0xf) {
		ipipe_trigger_irq(__ipipe_mach_hrtimer_irq);
		return;
	}

	__raw_writel(delay, twd_base + TWD_TIMER_COUNTER);
}
EXPORT_SYMBOL(__ipipe_mach_set_dec);

unsigned long __ipipe_mach_get_dec(void)
{
	return __raw_readl(twd_base + TWD_TIMER_COUNTER);
}

int __ipipe_check_tickdev(const char *devname)
{
	return !strcmp(devname, "local_timer");
}

int twd_timer_ack(void)
{
	/*
	 * Always true if we get there, already handled early by the
	 * pipeline.
	 */
	return 1;
}

static struct __ipipe_tscinfo tsc_info;

static void gt_register_tsc(void)
{
	if (tsc_info.u.mask == 0)
		return;
	tsc_info.freq = twd_timer_rate;
	__ipipe_tsc_register(&tsc_info);
}

void __cpuinit gt_setup(unsigned long base_paddr, unsigned bits)
{
	if (!gt_base) {
		gt_base = ioremap(base_paddr, SZ_256);
		BUG_ON(!gt_base);

		/* Start global timer */
		__raw_writel(1, gt_base + 0x8);

		tsc_info.type = IPIPE_TSC_TYPE_FREERUNNING;
		tsc_info.counter_vaddr = (unsigned long)gt_base;
		tsc_info.u.counter_paddr = base_paddr;

		switch(bits) {
		case 64:
			tsc_info.u.mask = 0xffffffffffffffffULL;
			break;
		case 32:
			tsc_info.u.mask = 0xffffffff;
			break;
		default:
			/* Only supported as a 32 bits or 64 bits */
			BUG();
		}

		gt_register_tsc();
	}
}

#ifdef CONFIG_IPIPE_DEBUG_INTERNAL

static DEFINE_PER_CPU(int, irqs);

void twd_hrtimer_debug(unsigned int irq) /* hw interrupt off */
{
	int cpu = ipipe_processor_id();

	if ((++per_cpu(irqs, cpu) % HZ) == 0) {
#if 0
		__ipipe_serial_debug("%c", 'A' + cpu);
#else
		do { } while (0);
#endif
	}
}
#endif /* CONFIG_IPIPE_DEBUG_INTERNAL */

void ipipe_twd_update_freq(void)
{
	twd_timer_rate = clk_get_rate(twd_clk);

	__ipipe_twd_hrtimer_freq = twd_timer_rate;
	printk(KERN_INFO "I-pipe, %u.%03u MHz timer\n",
	       __ipipe_twd_hrtimer_freq / 1000000,
	       (__ipipe_twd_hrtimer_freq % 1000000) / 1000);
	__ipipe_mach_ticks_per_jiffy = (twd_timer_rate + HZ / 2) / HZ;

	gt_register_tsc();
}
#else /* !CONFIG_IPIPE || !CONFIG_SMP*/

/*
 * local_timer_ack: checks for a local timer interrupt.
 *
 * If a local timer interrupt has occurred, acknowledge and return 1.
 * Otherwise, return 0.
 */
int twd_timer_ack(void)
{
	if (__raw_readl(twd_base + TWD_TIMER_INTSTAT)) {
		__raw_writel(1, twd_base + TWD_TIMER_INTSTAT);
		return 1;
	}

	return 0;
}

#define ipipe_twd_update_freq()
#endif /* !CONFIG_IPIPE || !CONFIG_SMP*/

static void twd_set_mode(enum clock_event_mode mode,
			struct clock_event_device *clk)
{
	unsigned long ctrl;

	switch (mode) {
	case CLOCK_EVT_MODE_PERIODIC:
		ctrl = TWD_TIMER_CONTROL_ENABLE | TWD_TIMER_CONTROL_IT_ENABLE
			| TWD_TIMER_CONTROL_PERIODIC;
		__raw_writel((twd_timer_rate + HZ / 2) / HZ, twd_base + TWD_TIMER_LOAD);
		gic_enable_ppi(clk->irq);
		break;
	case CLOCK_EVT_MODE_ONESHOT:
		/* period set, and timer enabled in 'next_event' hook */
		ctrl = TWD_TIMER_CONTROL_IT_ENABLE | TWD_TIMER_CONTROL_ONESHOT;
		gic_enable_ppi(clk->irq);
		break;
	case CLOCK_EVT_MODE_UNUSED:
	case CLOCK_EVT_MODE_SHUTDOWN:
	default:
		ctrl = 0;
		gic_disable_ppi(clk->irq);
	}

	__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);
#if defined(CONFIG_IPIPE) && defined(CONFIG_SMP)
	per_cpu(timer_mode, smp_processor_id()) = mode;
#endif
}

static int twd_set_next_event(unsigned long evt,
			struct clock_event_device *unused)
{
	unsigned long ctrl = __raw_readl(twd_base + TWD_TIMER_CONTROL);

	ctrl |= TWD_TIMER_CONTROL_ENABLE;

	__raw_writel(evt, twd_base + TWD_TIMER_COUNTER);
	__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);

	return 0;
}

static struct clk *twd_get_clock(void)
{
	return clk_get_sys("smp_twd", NULL);
}

#ifdef CONFIG_CPU_FREQ
/*
 * Updates clockevent frequency when the cpu frequency changes.
 * Called on the cpu that is changing frequency with interrupts disabled.
 */
static void twd_update_frequency(void *data)
{
	twd_timer_rate = clk_get_rate(twd_clk);

	clockevents_update_freq(*__this_cpu_ptr(twd_evt), twd_timer_rate);
}

static int twd_cpufreq_transition(struct notifier_block *nb,
	unsigned long state, void *data)
{
	struct cpufreq_freqs *freqs = data;

	/*
	 * The twd clock events must be reprogrammed to account for the new
	 * frequency.  The timer is local to a cpu, so cross-call to the
	 * changing cpu.
	 *
	 * Only wait for it to finish, if the cpu is active to avoid
	 * deadlock when cpu1 is spinning on while(!cpu_active(cpu1)) during
	 * booting of that cpu.
	 */
	if (state == CPUFREQ_POSTCHANGE || state == CPUFREQ_RESUMECHANGE)
		smp_call_function_single(freqs->cpu, twd_update_frequency,
					 NULL, cpu_active(freqs->cpu));

	return NOTIFY_OK;
}

static struct notifier_block twd_cpufreq_nb = {
	.notifier_call = twd_cpufreq_transition,
};

static int twd_cpufreq_init(void)
{
	if (twd_evt && *__this_cpu_ptr(twd_evt) && !IS_ERR(twd_clk))
		return cpufreq_register_notifier(&twd_cpufreq_nb,
			CPUFREQ_TRANSITION_NOTIFIER);

	return 0;
}
core_initcall(twd_cpufreq_init);

#endif

static void __cpuinit twd_calibrate_rate(void)
{
	unsigned long count;
	u64 waitjiffies;

	/*
	 * If this is the first time round, we need to work out how fast
	 * the timer ticks
	 */
	if (twd_timer_rate == 0) {
		printk(KERN_INFO "Calibrating local timer... ");

		/* Wait for a tick to start */
		waitjiffies = get_jiffies_64() + 1;

		while (get_jiffies_64() < waitjiffies)
			udelay(10);

		/* OK, now the tick has started, let's get the timer going */
		waitjiffies += 5;

				 /* enable, no interrupt or reload */
		__raw_writel(0x1, twd_base + TWD_TIMER_CONTROL);

				 /* maximum value */
		__raw_writel(0xFFFFFFFFU, twd_base + TWD_TIMER_COUNTER);

		while (get_jiffies_64() < waitjiffies)
			udelay(10);

		count = __raw_readl(twd_base + TWD_TIMER_COUNTER);

		twd_timer_rate = (0xFFFFFFFFU - count) * (HZ / 5);

		printk("%lu.%02luMHz.\n", twd_timer_rate / 1000000,
			(twd_timer_rate / 10000) % 100);
	}
}

/*
 * Setup the local clock events for a CPU.
 */
void __cpuinit twd_timer_setup(struct clock_event_device *clk)
{
	struct clock_event_device **this_cpu_clk;

	if (!twd_evt) {
		twd_evt = alloc_percpu(struct clock_event_device *);
		if (!twd_evt) {
			pr_err("twd: can't allocate memory\n");
			return;
		}

		if (!twd_clk)
			twd_clk = twd_get_clock();

		if (!IS_ERR_OR_NULL(twd_clk))
			twd_timer_rate = clk_get_rate(twd_clk);
		else
			twd_calibrate_rate();

		ipipe_twd_update_freq();
	}

	clk->name = "local_timer";
	clk->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT |
			CLOCK_EVT_FEAT_C3STOP;
	clk->rating = 350;
	clk->set_mode = twd_set_mode;
	clk->set_next_event = twd_set_next_event;

	this_cpu_clk = __this_cpu_ptr(twd_evt);
	*this_cpu_clk = clk;

	clockevents_config_and_register(clk, twd_timer_rate,
					0xf, 0xffffffff);

	/* Make sure our local interrupt controller has this enabled */
	gic_enable_ppi(clk->irq);
}
