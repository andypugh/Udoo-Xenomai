cmd_scripts/basic/fixdep := gcc -Wp,-MD,scripts/basic/.fixdep.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer     -o scripts/basic/fixdep scripts/basic/fixdep.c  

source_scripts/basic/fixdep := scripts/basic/fixdep.c

deps_scripts/basic/fixdep := \
    $(wildcard include/config/his/driver.h) \
    $(wildcard include/config/my/option.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \
    $(wildcard include/config/boom.h) \
  /usr/include/arm-linux-gnueabi/sys/types.h \
  /usr/include/features.h \
  /usr/include/arm-linux-gnueabi/bits/predefs.h \
  /usr/include/arm-linux-gnueabi/sys/cdefs.h \
  /usr/include/arm-linux-gnueabi/bits/wordsize.h \
  /usr/include/arm-linux-gnueabi/gnu/stubs.h \
  /usr/include/arm-linux-gnueabi/bits/types.h \
  /usr/include/arm-linux-gnueabi/bits/typesizes.h \
  /usr/include/time.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stddef.h \
  /usr/include/endian.h \
  /usr/include/arm-linux-gnueabi/bits/endian.h \
  /usr/include/arm-linux-gnueabi/bits/byteswap.h \
  /usr/include/arm-linux-gnueabi/sys/select.h \
  /usr/include/arm-linux-gnueabi/bits/select.h \
  /usr/include/arm-linux-gnueabi/bits/sigset.h \
  /usr/include/arm-linux-gnueabi/bits/time.h \
  /usr/include/arm-linux-gnueabi/bits/select2.h \
  /usr/include/arm-linux-gnueabi/sys/sysmacros.h \
  /usr/include/arm-linux-gnueabi/bits/pthreadtypes.h \
  /usr/include/arm-linux-gnueabi/sys/stat.h \
  /usr/include/arm-linux-gnueabi/bits/stat.h \
  /usr/include/arm-linux-gnueabi/sys/mman.h \
  /usr/include/arm-linux-gnueabi/bits/mman.h \
  /usr/include/unistd.h \
  /usr/include/arm-linux-gnueabi/bits/posix_opt.h \
  /usr/include/arm-linux-gnueabi/bits/environments.h \
  /usr/include/arm-linux-gnueabi/bits/confname.h \
  /usr/include/getopt.h \
  /usr/include/arm-linux-gnueabi/bits/unistd.h \
  /usr/include/fcntl.h \
  /usr/include/arm-linux-gnueabi/bits/fcntl.h \
  /usr/include/arm-linux-gnueabi/bits/fcntl2.h \
  /usr/include/string.h \
  /usr/include/xlocale.h \
  /usr/include/arm-linux-gnueabi/bits/string.h \
  /usr/include/arm-linux-gnueabi/bits/string2.h \
  /usr/include/stdlib.h \
  /usr/include/arm-linux-gnueabi/bits/string3.h \
  /usr/include/arm-linux-gnueabi/bits/waitflags.h \
  /usr/include/arm-linux-gnueabi/bits/waitstatus.h \
  /usr/include/alloca.h \
  /usr/include/arm-linux-gnueabi/bits/stdlib.h \
  /usr/include/stdio.h \
  /usr/include/libio.h \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stdarg.h \
  /usr/include/arm-linux-gnueabi/bits/stdio_lim.h \
  /usr/include/arm-linux-gnueabi/bits/sys_errlist.h \
  /usr/include/arm-linux-gnueabi/bits/stdio.h \
  /usr/include/arm-linux-gnueabi/bits/stdio2.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include-fixed/limits.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include-fixed/syslimits.h \
  /usr/include/limits.h \
  /usr/include/arm-linux-gnueabi/bits/posix1_lim.h \
  /usr/include/arm-linux-gnueabi/bits/local_lim.h \
  /usr/include/linux/limits.h \
  /usr/include/arm-linux-gnueabi/bits/posix2_lim.h \
  /usr/include/ctype.h \
  /usr/include/arpa/inet.h \
  /usr/include/netinet/in.h \
  /usr/lib/gcc/arm-linux-gnueabi/4.6/include/stdint.h \
  /usr/include/stdint.h \
  /usr/include/arm-linux-gnueabi/bits/wchar.h \
  /usr/include/arm-linux-gnueabi/sys/socket.h \
  /usr/include/arm-linux-gnueabi/sys/uio.h \
  /usr/include/arm-linux-gnueabi/bits/uio.h \
  /usr/include/arm-linux-gnueabi/bits/socket.h \
  /usr/include/arm-linux-gnueabi/bits/sockaddr.h \
  /usr/include/arm-linux-gnueabi/asm/socket.h \
  /usr/include/arm-linux-gnueabi/asm/sockios.h \
  /usr/include/arm-linux-gnueabi/bits/socket2.h \
  /usr/include/arm-linux-gnueabi/bits/in.h \

scripts/basic/fixdep: $(deps_scripts/basic/fixdep)

$(deps_scripts/basic/fixdep):
