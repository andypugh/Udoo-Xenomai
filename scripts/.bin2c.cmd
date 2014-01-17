cmd_scripts/bin2c := gcc -Wp,-MD,scripts/.bin2c.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer     -o scripts/bin2c scripts/bin2c.c  

source_scripts/bin2c := scripts/bin2c.c

deps_scripts/bin2c := \
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

scripts/bin2c: $(deps_scripts/bin2c)

$(deps_scripts/bin2c):
