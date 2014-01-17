cmd_firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o := gcc -Wp,-MD,firmware/imx/sdma/.sdma-imx6q-to1.bin.gen.o.d  -nostdinc -isystem /usr/lib/gcc/arm-linux-gnueabi/4.6/include -I/home/andypugh/git/Kernel_Unico/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-mx6/include -Iarch/arm/plat-mxc/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float        -c -o firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o firmware/imx/sdma/sdma-imx6q-to1.bin.gen.S

source_firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o := firmware/imx/sdma/sdma-imx6q-to1.bin.gen.S

deps_firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o := \
  /home/andypugh/git/Kernel_Unico/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \

firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o: $(deps_firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o)

$(deps_firmware/imx/sdma/sdma-imx6q-to1.bin.gen.o):
