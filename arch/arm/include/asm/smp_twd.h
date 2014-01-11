#ifndef __ASMARM_SMP_TWD_H
#define __ASMARM_SMP_TWD_H

#define TWD_TIMER_LOAD			0x00
#define TWD_TIMER_COUNTER		0x04
#define TWD_TIMER_CONTROL		0x08
#define TWD_TIMER_INTSTAT		0x0C

#define TWD_WDOG_LOAD			0x20
#define TWD_WDOG_COUNTER		0x24
#define TWD_WDOG_CONTROL		0x28
#define TWD_WDOG_INTSTAT		0x2C
#define TWD_WDOG_RESETSTAT		0x30
#define TWD_WDOG_DISABLE		0x34

#define TWD_TIMER_CONTROL_ENABLE	(1 << 0)
#define TWD_TIMER_CONTROL_ONESHOT	(0 << 1)
#define TWD_TIMER_CONTROL_PERIODIC	(1 << 1)
#define TWD_TIMER_CONTROL_IT_ENABLE	(1 << 2)

struct clock_event_device;

extern void __iomem *twd_base;

#ifdef CONFIG_IPIPE

#define __ipipe_mach_hrtimer_irq 29

#define __ipipe_mach_ipi_p(irq) ((irq) < 16)

#define __ipipe_mach_ext_hrtimer(cpu) __ipipe_mach_hrtimer_irq

#define __ipipe_mach_localtimer(irq) (irq)

#define __ipipe_twd_localtimer_p(irq) ((irq) == __ipipe_mach_hrtimer_irq)

#define __ipipe_mach_doirq(irq)					\
	({							\
		__ipipe_mach_ipi_p(irq)				\
			? __ipipe_root_ipi			\
			: __ipipe_twd_localtimer_p(irq)		\
			? __ipipe_root_localtimer		\
			: __ipipe_do_IRQ;			\
	})

#define __ipipe_mach_ackirq(irq)					\
	({								\
		__ipipe_mach_ipi_p(irq)					\
			? NULL						\
			: __ipipe_twd_localtimer_p(irq)			\
			? __ipipe_ack_localtimer			\
			: __ipipe_ack_irq;				\
	})

#define __ipipe_mach_relay_ipi(ipi, thiscpu)	\
	({					\
		(void)(thiscpu);		\
		__ipipe_handle_irq(ipi, IPIPE_IRQF_NOACK);	\
	})

struct irq_desc;

void __ipipe_ack_localtimer(unsigned int irq, struct irq_desc *desc);

#ifdef CONFIG_IPIPE_DEBUG_INTERNAL
void twd_hrtimer_debug(unsigned int irq);
#define __ipipe_mach_hrtimer_debug(irq)	twd_hrtimer_debug(irq)
#else
#define __ipipe_mach_hrtimer_debug(irq)	do { } while (0)
#endif

extern unsigned __ipipe_twd_hrtimer_freq;
#define __ipipe_mach_hrtimer_freq	__ipipe_twd_hrtimer_freq

void ipipe_twd_update_freq(void);

/* Global timer setup, the global timer is a convenient 64 bits
 * high-resoluion counter, part of the cortex a9 mpcore */
void gt_setup(unsigned long base_paddr, unsigned bits);
#endif /* CONFIG_IPIPE */

int twd_timer_ack(void);
void twd_timer_setup(struct clock_event_device *);
#endif
