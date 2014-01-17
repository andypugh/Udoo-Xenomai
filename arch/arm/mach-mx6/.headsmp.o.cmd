cmd_arch/arm/mach-mx6/headsmp.o := gcc -Wp,-MD,arch/arm/mach-mx6/.headsmp.o.d  -nostdinc -isystem /usr/lib/gcc/arm-linux-gnueabi/4.6/include -I/home/andypugh/git/Kernel_Unico/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-mx6/include -Iarch/arm/plat-mxc/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float        -c -o arch/arm/mach-mx6/headsmp.o arch/arm/mach-mx6/headsmp.S

source_arch/arm/mach-mx6/headsmp.o := arch/arm/mach-mx6/headsmp.S

deps_arch/arm/mach-mx6/headsmp.o := \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/linkage.h \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \

arch/arm/mach-mx6/headsmp.o: $(deps_arch/arm/mach-mx6/headsmp.o)

$(deps_arch/arm/mach-mx6/headsmp.o):
