#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe15b7730, "module_layout" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb78c61e8, "param_ops_bool" },
	{ 0x7d11c268, "jiffies" },
	{ 0x83771fe3, "i2c_add_adapter" },
	{ 0xb5c63e4c, "dev_err" },
	{ 0x27e1a049, "printk" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x3f54ff48, "i2c_add_numbered_adapter" },
	{ 0xbeac7f79, "dev_warn" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x760a0f4f, "yield" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

