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
	{ 0xbd76ad7f, "drm_release" },
	{ 0xc6eba7d0, "drm_core_reclaim_buffers" },
	{ 0x69a6e1ec, "drm_mmap" },
	{ 0x27e1a049, "printk" },
	{ 0x899e2ede, "drm_platform_exit" },
	{ 0xd836bab0, "noop_llseek" },
	{ 0x5b73bb10, "platform_device_unregister" },
	{ 0x2cb1ef3d, "drm_platform_init" },
	{ 0x78398d35, "drm_ioctl" },
	{ 0x20d14fc, "platform_device_register_resndata" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x1c9abee7, "drm_poll" },
	{ 0x1d9e30b7, "drm_fasync" },
	{ 0x87bbe305, "drm_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=drm";

