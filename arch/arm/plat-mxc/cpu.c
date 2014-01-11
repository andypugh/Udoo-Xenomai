
#include <linux/module.h>

unsigned int __mxc_cpu_type;
EXPORT_SYMBOL(__mxc_cpu_type);

void mxc_set_cpu_type(unsigned int type)
{
	__mxc_cpu_type = type;
}

static int __init setup_debug_uart(char *p)
{
	uart_at_24 = 1;
	return 0;
}

early_param("debug_uart", setup_debug_uart);
