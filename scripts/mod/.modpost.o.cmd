cmd_scripts/mod/modpost.o := gcc -Wp,-MD,scripts/mod/.modpost.o.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer     -c -o scripts/mod/modpost.o scripts/mod/modpost.c

source_scripts/mod/modpost.o := scripts/mod/modpost.c

deps_scripts/mod/modpost.o := \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/srcversion/all.h) \
    $(wildcard include/config/relocatable.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/debug/section/mismatch.h) \
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
  /usr/include/ctype.h \
  /usr/include/endian.h \
  /usr/include/arm-linux-gnueabi/bits/endian.h \
  /usr/include/arm-linux-gnueabi/bits/byteswap.h \
  /usr/include/xlocale.h \
  /usr/include/string.h \
  /usr/include/arm-linux-gnueabi/bits/string.h \
  /usr/include/arm-linux-gnueabi/bits/string2.h \
  /usr/include/stdlib.h \
  /usr/include/arm-linux-gnueabi/bits/string3.h \
  scripts/mod/modpost.h \
  /usr/include/arm-linux-gnueabi/bits/waitflags.h \
  /usr/include/arm-linux-gnueabi/bits/waitstatus.h \
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
  /usr/include/arm-linux-gnueabi/sys/stat.h \
  /usr/include/arm-linux-gnueabi/bits/stat.h \
  /usr/include/arm-linux-gnueabi/sys/mman.h \
  /usr/include/arm-linux-gnueabi/bits/mman.h \
  /usr/include/fcntl.h \
  /usr/include/arm-linux-gnueabi/bits/fcntl.h \
  /usr/include/arm-linux-gnueabi/bits/uio.h \
  /usr/include/arm-linux-gnueabi/bits/fcntl2.h \
  /usr/include/unistd.h \
  /usr/include/arm-linux-gnueabi/bits/posix_opt.h \
  /usr/include/arm-linux-gnueabi/bits/environments.h \
  /usr/include/arm-linux-gnueabi/bits/confname.h \
  /usr/include/getopt.h \
  /usr/include/arm-linux-gnueabi/bits/unistd.h \
  /usr/include/elf.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stdint.h \
  /usr/include/stdint.h \
  /usr/include/arm-linux-gnueabi/bits/wchar.h \
  scripts/mod/elfconfig.h \
  scripts/mod/../../include/linux/license.h \

scripts/mod/modpost.o: $(deps_scripts/mod/modpost.o)

$(deps_scripts/mod/modpost.o):
