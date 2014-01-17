cmd_scripts/mod/mk_elfconfig := gcc -Wp,-MD,scripts/mod/.mk_elfconfig.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer     -o scripts/mod/mk_elfconfig scripts/mod/mk_elfconfig.c  

source_scripts/mod/mk_elfconfig := scripts/mod/mk_elfconfig.c

deps_scripts/mod/mk_elfconfig := \
  /usr/include/stdio.h \
  /usr/include/features.h \
  /usr/include/arm-linux-gnueabi/bits/predefs.h \
  /usr/include/arm-linux-gnueabi/sys/cdefs.h \
  /usr/include/arm-linux-gnueabi/bits/wordsize.h \
  /usr/include/arm-linux-gnueabi/gnu/stubs.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stddef.h \
  /usr/include/arm-linux-gnueabi/bits/types.h \
  /usr/include/arm-linux-gnueabi/bits/typesizes.h \
  /usr/include/libio.h \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stdarg.h \
  /usr/include/arm-linux-gnueabi/bits/stdio_lim.h \
  /usr/include/arm-linux-gnueabi/bits/sys_errlist.h \
  /usr/include/arm-linux-gnueabi/bits/stdio.h \
  /usr/include/arm-linux-gnueabi/bits/stdio2.h \
  /usr/include/stdlib.h \
  /usr/include/arm-linux-gnueabi/bits/waitflags.h \
  /usr/include/arm-linux-gnueabi/bits/waitstatus.h \
  /usr/include/endian.h \
  /usr/include/arm-linux-gnueabi/bits/endian.h \
  /usr/include/arm-linux-gnueabi/bits/byteswap.h \
  /usr/include/arm-linux-gnueabi/sys/types.h \
  /usr/include/time.h \
  /usr/include/arm-linux-gnueabi/sys/select.h \
  /usr/include/arm-linux-gnueabi/bits/select.h \
  /usr/include/arm-linux-gnueabi/bits/sigset.h \
  /usr/include/arm-linux-gnueabi/bits/time.h \
  /usr/include/arm-linux-gnueabi/bits/select2.h \
  /usr/include/arm-linux-gnueabi/sys/sysmacros.h \
  /usr/include/arm-linux-gnueabi/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /usr/include/arm-linux-gnueabi/bits/stdlib.h \
  /usr/include/string.h \
  /usr/include/xlocale.h \
  /usr/include/arm-linux-gnueabi/bits/string.h \
  /usr/include/arm-linux-gnueabi/bits/string2.h \
  /usr/include/arm-linux-gnueabi/bits/string3.h \
  /usr/include/elf.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stdint.h \
  /usr/include/stdint.h \
  /usr/include/arm-linux-gnueabi/bits/wchar.h \

scripts/mod/mk_elfconfig: $(deps_scripts/mod/mk_elfconfig)

$(deps_scripts/mod/mk_elfconfig):
