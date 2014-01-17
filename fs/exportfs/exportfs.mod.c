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
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0x487a6a71, "mntget" },
	{ 0x5f485ae8, "vfs_readdir" },
	{ 0x97255bdf, "strlen" },
	{ 0x391f5002, "dget_parent" },
	{ 0x7cfabc1, "dput" },
	{ 0x10f8e95, "dentry_open" },
	{ 0x9e2e406c, "mutex_unlock" },
	{ 0x27e1a049, "printk" },
	{ 0x20d67846, "mutex_lock" },
	{ 0xf4e43be0, "fput" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0x9d669763, "memcpy" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xa90e5b59, "lookup_one_len" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

