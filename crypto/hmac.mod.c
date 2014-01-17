#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe15b7730, "module_layout" },
	{ 0xbf01defa, "crypto_unregister_template" },
	{ 0x2e1f0ba0, "crypto_register_template" },
	{ 0x7bd7bb01, "shash_register_instance" },
	{ 0xe1e7913b, "crypto_mod_put" },
	{ 0x928ecdc0, "shash_free_instance" },
	{ 0x7cb16aa, "crypto_init_shash_spawn" },
	{ 0x530f2b71, "crypto_alloc_instance2" },
	{ 0x1f625882, "shash_attr_alg" },
	{ 0xd16712f3, "crypto_check_attr_type" },
	{ 0xa6067da5, "crypto_spawn_tfm2" },
	{ 0x5bf5889a, "crypto_destroy_tfm" },
	{ 0xa26c9009, "crypto_shash_final" },
	{ 0xeb5f151e, "crypto_shash_finup" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x9d669763, "memcpy" },
	{ 0x5cc27798, "crypto_shash_digest" },
	{ 0x23674532, "crypto_shash_update" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

