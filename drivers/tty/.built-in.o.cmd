cmd_drivers/tty/built-in.o :=  ld -EL    -r -o drivers/tty/built-in.o drivers/tty/tty_io.o drivers/tty/n_tty.o drivers/tty/tty_ioctl.o drivers/tty/tty_ldisc.o drivers/tty/tty_buffer.o drivers/tty/tty_port.o drivers/tty/tty_mutex.o drivers/tty/pty.o drivers/tty/sysrq.o drivers/tty/vt/built-in.o drivers/tty/serial/built-in.o drivers/tty/ipwireless/built-in.o 
