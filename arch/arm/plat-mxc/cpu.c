/*
 * Copyright (C) 2011-2012 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <linux/module.h>
#include <mach/clock.h>
#include <linux/io.h>
#include <mach/hardware.h>

unsigned int __mxc_cpu_type;
EXPORT_SYMBOL(__mxc_cpu_type);
extern int mxc_early_serial_console_init(unsigned long base, struct clk *clk);
void (*set_num_cpu_op)(int num);

void mxc_set_cpu_type(unsigned int type)
{
	__mxc_cpu_type = type;
}

void imx_print_silicon_rev(const char *cpu, int srev)
{
	if (srev == IMX_CHIP_REVISION_UNKNOWN)
		pr_info("CPU identified as %s, unknown revision\n", cpu);
	else
		pr_info("CPU identified as %s, silicon rev %d.%d\n",
				cpu, (srev >> 4) & 0xf, srev & 0xf);
}

int mxc_jtag_enabled;		/* OFF: 0 (default), ON: 1 */
int uart_at_24; 			/* OFF: 0 (default); ON: 1 */
/*
 * Here are the JTAG options from the command line. By default JTAG
 * is OFF which means JTAG is not connected and WFI is enabled
 *
 *       "on" --  JTAG is connected, so WFI is disabled
 *       "off" -- JTAG is disconnected, so WFI is enabled
 */

static int __init jtag_wfi_setup(char *p)
{
	if (memcmp(p, "on", 2) == 0) {
		mxc_jtag_enabled = 1;
		p += 2;
	} else if (memcmp(p, "off", 3) == 0) {
		mxc_jtag_enabled = 0;
		p += 3;
	}
	return 0;
}
early_param("jtag", jtag_wfi_setup);


static int __init setup_debug_uart(char *p)
{
	uart_at_24 = 1;
	return 0;
}

early_param("debug_uart", setup_debug_uart);

/**
 * early_console_setup - setup debugging console
 *
 * Consoles started here require little enough setup that we can start using
 * them very early in the boot process, either right after the machine
 * vector initialization, or even before if the drivers can detect their hw.
 *
 * Returns non-zero if a console couldn't be setup.
 * This function is developed based on
 * early_console_setup function as defined in arch/ia64/kernel/setup.c
 */
void __init early_console_setup(unsigned long base, struct clk *clk)
{
#ifdef CONFIG_SERIAL_IMX_CONSOLE
	mxc_early_serial_console_init(base, clk);
#endif
}

#ifdef CONFIG_IPIPE
void ipipe_mach_allow_hwtimer_uaccess(unsigned long aips1, unsigned long aips2)
{
    volatile unsigned long aips_reg;

    if (!cpu_is_mx27()) {
        /*
         * S/W workaround: Clear the off platform peripheral modules
         * Supervisor Protect bit for SDMA to access them.
         */
        __raw_writel(0x0, aips1 + 0x40);
        __raw_writel(0x0, aips1 + 0x44);
        __raw_writel(0x0, aips1 + 0x48);
        __raw_writel(0x0, aips1 + 0x4C);
        aips_reg = __raw_readl(aips1 + 0x50);
        aips_reg &= 0x00FFFFFF;
        __raw_writel(aips_reg, aips1 + 0x50);

        __raw_writel(0x0, aips2 + 0x40);
        __raw_writel(0x0, aips2 + 0x44);
        __raw_writel(0x0, aips2 + 0x48);
        __raw_writel(0x0, aips2 + 0x4C);
        aips_reg = __raw_readl(aips2 + 0x50);
        aips_reg &= 0x00FFFFFF;
        __raw_writel(aips_reg, aips2 + 0x50);
    } else {
        aips_reg = __raw_readl(aips1 + 8);
        aips_reg &= ~(1 << aips2);
        __raw_writel(aips_reg, aips1 + 8);
    }
}
#endif /* CONFIG_IPIPE */
