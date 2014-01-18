cmd_kernel/xenomai/nucleus/module.o := gcc -Wp,-MD,kernel/xenomai/nucleus/.module.o.d  -nostdinc -isystem /usr/lib/gcc/arm-linux-gnueabi/4.6/include -I/home/andypugh/git/Kernel_Unico/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-mx6/include -Iarch/arm/plat-mxc/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -marm -fno-dwarf2-cfi-asm -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -D__IN_XENOMAI__ -Iinclude/xenomai    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(module)"  -D"KBUILD_MODNAME=KBUILD_STR(xeno_nucleus)" -c -o kernel/xenomai/nucleus/.tmp_module.o kernel/xenomai/nucleus/module.c

source_kernel/xenomai/nucleus/module.o := kernel/xenomai/nucleus/module.c

deps_kernel/xenomai/nucleus/module.o := \
    $(wildcard include/config/xeno/opt/pipe.h) \
    $(wildcard include/config/xeno/opt/pervasive.h) \
    $(wildcard include/config/xeno/opt/hostrt.h) \
    $(wildcard include/config/xeno/opt/sys/heapsz.h) \
    $(wildcard include/config/xeno/opt/global/sem/heapsz.h) \
    $(wildcard include/config/xeno/opt/select.h) \
    $(wildcard include/config/xeno/opt/debug.h) \
  include/xenomai/nucleus/module.h \
  include/xenomai/nucleus/queue.h \
    $(wildcard include/config/smp.h) \
  include/xenomai/nucleus/types.h \
  include/linux/errno.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/system.h \
    $(wildcard include/config/xeno/hw/fpu.h) \
    $(wildcard include/config/xeno/arm/eabi.h) \
    $(wildcard include/config/arm/thumb.h) \
    $(wildcard include/config/crunch.h) \
    $(wildcard include/config/vfp.h) \
    $(wildcard include/config/cpu/v7.h) \
    $(wildcard include/config/neon.h) \
    $(wildcard include/config/iwmmxt.h) \
  include/linux/ptrace.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/hwcap.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/posix_types.h \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/ipipe.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/preempt/notifiers.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/mm/owner.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/linux/capability.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stdarg.h \
  include/linux/linkage.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/linkage.h \
  include/linux/bitops.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/bitops.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/system.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/ipipe/want/preemptible/switch.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/irqflags.h \
    $(wildcard include/config/ipipe/trace/irqsoff.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/le.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/ipipe_base.h \
    $(wildcard include/config/ipipe/debug/context.h) \
    $(wildcard include/config/generic/clockevents.h) \
    $(wildcard include/config/have/ipipe/hostrt.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/ipipe_base.h \
    $(wildcard include/config/ipipe/arm/kuser/tsc.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/irq.h \
  arch/arm/plat-mxc/include/mach/irqs.h \
    $(wildcard include/config/mxc/tzic.h) \
    $(wildcard include/config/arm/gic.h) \
    $(wildcard include/config/soc/imx53.h) \
    $(wildcard include/config/arch/mx2.h) \
    $(wildcard include/config/soc/imx50.h) \
    $(wildcard include/config/arch/mx1.h) \
    $(wildcard include/config/arch/mx25.h) \
    $(wildcard include/config/soc/imx51.h) \
    $(wildcard include/config/arch/mx3.h) \
    $(wildcard include/config/arch/mx6.h) \
    $(wildcard include/config/mach/mx31ads/wm1133/ev1.h) \
    $(wildcard include/config/mx3/ipu/irqs.h) \
    $(wildcard include/config/arch/mx5.h) \
    $(wildcard include/config/soc/imx6q.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/smp_twd.h \
    $(wildcard include/config/ipipe/debug/internal.h) \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/dynamic_debug.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/div64.h \
  include/linux/timex.h \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
  include/linux/thread_info.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
    $(wildcard include/config/arm/fcse.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/const.h \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lock/stat.h) \
  include/linux/rwlock_types.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/spinlock.h \
    $(wildcard include/config/thumb2/kernel.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/processor.h \
    $(wildcard include/config/arm/errata/754327.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/hw_breakpoint.h \
  include/linux/ipipe_lock.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/inline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  include/asm-generic/atomic-long.h \
  include/linux/math64.h \
  include/linux/param.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/timex.h \
  arch/arm/plat-mxc/include/mach/timex.h \
  include/linux/jiffies.h \
  include/linux/rbtree.h \
  include/linux/cpumask.h \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/string.h \
  include/linux/nodemask.h \
    $(wildcard include/config/highmem.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/transparent/hugepage.h) \
  include/linux/auxvec.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/auxvec.h \
  include/linux/prio_tree.h \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/completion.h \
  include/linux/wait.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/current.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/glue.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/arm/patch/phys/virt/16bit.h) \
  arch/arm/plat-mxc/include/mach/memory.h \
    $(wildcard include/config/runtime/phys/offset.h) \
    $(wildcard include/config/mach/mx21.h) \
    $(wildcard include/config/mach/mx27.h) \
    $(wildcard include/config/arch/mx50.h) \
    $(wildcard include/config/arch/mx51.h) \
    $(wildcard include/config/arch/mx53.h) \
    $(wildcard include/config/mx3/video.h) \
    $(wildcard include/config/mx1/video.h) \
    $(wildcard include/config/video/mx2/hostsupport.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/sizes.h \
  include/asm-generic/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  include/asm-generic/getorder.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/mmu.h \
    $(wildcard include/config/cpu/has/asid.h) \
    $(wildcard include/config/arm/fcse/best/effort.h) \
  include/linux/ipipe.h \
    $(wildcard include/config/ipipe/trace.h) \
    $(wildcard include/config/ipipe/debug.h) \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/smp.h \
  include/linux/pfn.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  include/linux/mutex.h \
    $(wildcard include/config/have/arch/mutex/cpu/relax.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/ipipe.h \
    $(wildcard include/config/debug/ll.h) \
    $(wildcard include/config/serial/8250/console.h) \
  include/linux/ipipe_percpu.h \
    $(wildcard include/config/ipipe/domains.h) \
  include/linux/ipipe_trace.h \
    $(wildcard include/config/ipipe/trace/panic.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/ipcbuf.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/sembuf.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/preempt/rt.h) \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/rcutree.h \
  include/linux/signal.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/signal.h \
  include/asm-generic/signal-defs.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/sigcontext.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/pid.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  include/linux/notifier.h \
  include/linux/srcu.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/topology.h \
  include/asm-generic/topology.h \
  include/linux/proportions.h \
  include/linux/percpu_counter.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  include/linux/rculist.h \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/resource.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/timerfd.h) \
  include/linux/timerqueue.h \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/latencytop.h \
  include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/user/ns.h) \
  include/linux/key.h \
    $(wildcard include/config/sysctl.h) \
  include/linux/sysctl.h \
  include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  include/linux/aio.h \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/asm-generic/xenomai/system.h \
    $(wildcard include/config/xeno/opt/debug/xnlock.h) \
  include/linux/version.h \
  include/linux/module.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  include/linux/stat.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/stat.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/elf.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/user.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  include/linux/tracepoint.h \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/module.h \
    $(wildcard include/config/arm/unwind.h) \
  include/trace/events/module.h \
  include/trace/define_trace.h \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/slab.h) \
  include/linux/slub_def.h \
    $(wildcard include/config/slub/stats.h) \
    $(wildcard include/config/slub/debug.h) \
  include/linux/kmemleak.h \
    $(wildcard include/config/debug/kmemleak.h) \
  include/linux/vmalloc.h \
  include/linux/mm.h \
    $(wildcard include/config/ksm.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  include/linux/range.h \
  include/linux/bit_spinlock.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/pgtable.h \
    $(wildcard include/config/arm/fcse/guaranteed.h) \
    $(wildcard include/config/highpte.h) \
  include/asm-generic/4level-fixup.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/proc-fns.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/glue-proc.h \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm7tdmi.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/cpu/arm720t.h) \
    $(wildcard include/config/cpu/arm740t.h) \
    $(wildcard include/config/cpu/arm9tdmi.h) \
    $(wildcard include/config/cpu/arm920t.h) \
    $(wildcard include/config/cpu/arm922t.h) \
    $(wildcard include/config/cpu/arm925t.h) \
    $(wildcard include/config/cpu/arm926t.h) \
    $(wildcard include/config/cpu/arm940t.h) \
    $(wildcard include/config/cpu/arm946e.h) \
    $(wildcard include/config/cpu/arm1020.h) \
    $(wildcard include/config/cpu/arm1020e.h) \
    $(wildcard include/config/cpu/arm1022.h) \
    $(wildcard include/config/cpu/arm1026.h) \
    $(wildcard include/config/cpu/mohawk.h) \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/cpu/v6k.h) \
  arch/arm/plat-mxc/include/mach/vmalloc.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/pgtable-hwdef.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/fcse.h \
    $(wildcard include/config/arm/fcse/debug.h) \
    $(wildcard include/config/arm/fcse/dynpid.h) \
    $(wildcard include/config/arm/fcse/messages.h) \
  include/asm-generic/pgtable.h \
  include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/s390.h) \
  include/linux/huge_mm.h \
  include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
  include/linux/vm_event_item.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/uaccess.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/mmu_context.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/cacheflush.h \
    $(wildcard include/config/smp/on/up.h) \
    $(wildcard include/config/arm/errata/411920.h) \
    $(wildcard include/config/cpu/cache/vipt.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/glue-cache.h \
    $(wildcard include/config/cpu/cache/v3.h) \
    $(wildcard include/config/cpu/cache/v4.h) \
    $(wildcard include/config/cpu/cache/v4wb.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/shmparam.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/cachetype.h \
    $(wildcard include/config/cpu/cache/vivt.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/hal.h \
    $(wildcard include/config/ipipe/core.h) \
    $(wildcard include/config/arch/at91.h) \
    $(wildcard include/config/ipipe/at91/tc.h) \
    $(wildcard include/config/arch/imx.h) \
    $(wildcard include/config/arch/imx21.h) \
    $(wildcard include/config/arch/integrator.h) \
    $(wildcard include/config/arch/ixp4xx.h) \
    $(wildcard include/config/arch/mxc.h) \
    $(wildcard include/config/arch/omap3.h) \
    $(wildcard include/config/arch/omap4.h) \
    $(wildcard include/config/plat/orion.h) \
    $(wildcard include/config/arch/pxa.h) \
    $(wildcard include/config/arch/s3c2410.h) \
    $(wildcard include/config/arch/sa1100.h) \
    $(wildcard include/config/have/arm/twd.h) \
    $(wildcard include/config/plat/spear.h) \
    $(wildcard include/config/xeno/hw/unlocked/switch.h) \
    $(wildcard include/config/vfp/3/2/backport.h) \
  include/asm-generic/xenomai/hal.h \
    $(wildcard include/config/xeno/opt/pipeline/head.h) \
  include/linux/kallsyms.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/wrappers.h \
    $(wildcard include/config/ipipe/unmasked/context/switch.h) \
  include/linux/interrupt.h \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
  include/linux/irqreturn.h \
  include/linux/irqnr.h \
    $(wildcard include/config/sparse/irq.h) \
  include/linux/hardirq.h \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/hardirq.h \
    $(wildcard include/config/local/timers.h) \
  include/linux/irq_cpustat.h \
  include/trace/events/irq.h \
  include/asm-generic/xenomai/wrappers.h \
    $(wildcard include/config/ltt.h) \
    $(wildcard include/config/markers.h) \
    $(wildcard include/config/xeno/opt/vfile.h) \
  include/linux/ipipe_tickdev.h \
    $(wildcard include/config/ipipe/hostrt.h) \
  include/linux/clocksource.h \
    $(wildcard include/config/clocksource/watchdog.h) \
    $(wildcard include/config/generic/time/vsyscall.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/io.h \
  arch/arm/plat-mxc/include/mach/io.h \
    $(wildcard include/config/soc/imx31.h) \
    $(wildcard include/config/soc/imx35.h) \
  include/linux/clockchips.h \
    $(wildcard include/config/generic/clockevents/build.h) \
    $(wildcard include/config/generic/clockevents/broadcast.h) \
    $(wildcard include/config/tick/oneshot.h) \
  include/linux/semaphore.h \
  include/linux/seq_file.h \
  include/linux/proc_fs.h \
    $(wildcard include/config/proc/devicetree.h) \
    $(wildcard include/config/proc/kcore.h) \
  include/linux/fs.h \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  include/linux/limits.h \
  include/linux/ioctl.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/linux/blk_types.h \
    $(wildcard include/config/blk/dev/integrity.h) \
  include/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/rculist_bl.h \
  include/linux/list_bl.h \
  include/linux/path.h \
  include/linux/radix-tree.h \
  include/linux/fiemap.h \
  include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  include/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/nfs_fs_i.h \
  include/linux/nfs.h \
  include/linux/sunrpc/msg_prot.h \
  include/linux/inet.h \
  include/linux/fcntl.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/fcntl.h \
  include/asm-generic/fcntl.h \
  include/linux/err.h \
  include/linux/magic.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/arith.h \
    $(wildcard include/config/ftrace.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/features.h \
    $(wildcard include/config/xeno/arm/sa1000.h) \
    $(wildcard include/config/xeno/arm/kuser/tsc.h) \
    $(wildcard include/config/xeno/fastsynch.h) \
    $(wildcard include/config/xeno/arm/tsc/type.h) \
    $(wildcard include/config/xeno/arm/sa1100.h) \
  include/asm-generic/xenomai/features.h \
  include/asm-generic/xenomai/arith.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/vfp.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/atomic.h \
    $(wildcard include/config/xeno/atomic/builtins.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/atomic_asm.h \
    $(wildcard include/config/xeno/cpu/xsc3.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/mach/irq.h \
    $(wildcard include/config/multi/irq/handler.h) \
  include/linux/irq.h \
    $(wildcard include/config/irq/release/method.h) \
    $(wildcard include/config/generic/pending/irq.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/irq_regs.h \
  include/asm-generic/irq_regs.h \
  include/linux/irqdesc.h \
    $(wildcard include/config/irq/preflow/fasteoi.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/hw_irq.h \
  include/asm-generic/xenomai/timeconv.h \
  include/xenomai/nucleus/shadow.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/syscall.h \
    $(wildcard include/config/oabi/compat.h) \
  include/asm-generic/xenomai/syscall.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/tsc.h \
  include/xenomai/nucleus/assert.h \
    $(wildcard include/config/xeno/opt/debug/.h) \
    $(wildcard include/config/xeno/opt/debug/queues.h) \
    $(wildcard include/config/xeno/opt/debug/nucleus.h) \
  include/xenomai/nucleus/compiler.h \
    $(wildcard include/config/xeno/opt/nowarn/deprecated.h) \
  include/xenomai/nucleus/timebase.h \
    $(wildcard include/config/xeno/opt/stats.h) \
    $(wildcard include/config/xeno/opt/timing/periodic.h) \
  include/xenomai/nucleus/vfile.h \
  include/xenomai/nucleus/pod.h \
  include/xenomai/nucleus/sched.h \
    $(wildcard include/config/xeno/opt/priocpl.h) \
    $(wildcard include/config/xeno/opt/sched/tp.h) \
    $(wildcard include/config/xeno/opt/sched/sporadic.h) \
    $(wildcard include/config/xeno/opt/watchdog.h) \
    $(wildcard include/config/xeno/opt/sched/classes.h) \
  include/xenomai/nucleus/thread.h \
    $(wildcard include/config/xeno/skin/posix.h) \
  include/xenomai/nucleus/stat.h \
  include/xenomai/nucleus/timer.h \
    $(wildcard include/config/xeno/opt/debug/timers.h) \
    $(wildcard include/config/xeno/opt/timer/heap.h) \
    $(wildcard include/config/xeno/opt/timer/heap/capacity.h) \
    $(wildcard include/config/xeno/opt/timer/wheel.h) \
    $(wildcard include/config/xeno/opt/timer/wheel/step.h) \
    $(wildcard include/config/xeno/opt/timer/list.h) \
  include/xenomai/nucleus/registry.h \
    $(wildcard include/config/xeno/opt/registry/nrslots.h) \
  include/xenomai/nucleus/synch.h \
    $(wildcard include/config/xeno/opt/debug/synch/relax.h) \
  include/xenomai/nucleus/schedparam.h \
  include/xenomai/nucleus/schedqueue.h \
    $(wildcard include/config/xeno/opt/scalable/sched.h) \
  include/xenomai/nucleus/sched-tp.h \
    $(wildcard include/config/xeno/opt/sched/tp/nrpart.h) \
  include/xenomai/nucleus/sched-sporadic.h \
    $(wildcard include/config/xeno/opt/sched/sporadic/maxrepl.h) \
  include/xenomai/nucleus/sched-idle.h \
  include/xenomai/nucleus/sched-rt.h \
  include/xenomai/nucleus/heap.h \
    $(wildcard include/config/xeno/opt/sys/stackpoolsz.h) \
  include/xenomai/nucleus/intr.h \
    $(wildcard include/config/xeno/opt/shirq.h) \
  include/xenomai/nucleus/version.h \
    $(wildcard include/config/xeno/version/major.h) \
    $(wildcard include/config/xeno/version/minor.h) \
    $(wildcard include/config/xeno/revision/level.h) \
  include/xenomai/nucleus/sys_ppd.h \
  include/xenomai/nucleus/ppd.h \
  include/xenomai/nucleus/pipe.h \
    $(wildcard include/config/xeno/opt/pipe/nrdev.h) \
  include/linux/poll.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/poll.h \
  include/asm-generic/poll.h \
  include/xenomai/nucleus/select.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/bits/init.h \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/xenomai/calibration.h \
    $(wildcard include/config/xeno/opt/timing/schedlat.h) \
    $(wildcard include/config/arch/at91rm9200.h) \
    $(wildcard include/config/arch/at91sam9263.h) \
    $(wildcard include/config/arch/omap.h) \
  include/asm-generic/xenomai/bits/timeconv.h \
  include/xenomai/nucleus/vdso.h \
  include/xenomai/nucleus/hostrt.h \
  include/xenomai/nucleus/seqlock.h \

kernel/xenomai/nucleus/module.o: $(deps_kernel/xenomai/nucleus/module.o)

$(deps_kernel/xenomai/nucleus/module.o):