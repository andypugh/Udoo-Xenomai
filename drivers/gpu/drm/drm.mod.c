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
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xe90dcae0, "__request_module" },
	{ 0x5dd82feb, "device_remove_file" },
	{ 0x3dbd9bc9, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xd5b037e1, "kref_put" },
	{ 0xff178f6, "__aeabi_idivmod" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x4178302d, "sysfs_remove_bin_file" },
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0xe35d49f9, "debugfs_create_dir" },
	{ 0x70143367, "mem_map" },
	{ 0xb747fcea, "single_open" },
	{ 0x3ec8886f, "param_ops_int" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x1b945caf, "del_timer" },
	{ 0x97255bdf, "strlen" },
	{ 0x2c8aaadd, "dev_set_drvdata" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x8e67ddd4, "send_sig" },
	{ 0xf1deabf2, "div64_u64" },
	{ 0x6db92490, "single_release" },
	{ 0x718565d5, "remove_wait_queue" },
	{ 0xa00ab81e, "pci_disable_device" },
	{ 0xddcf3bb8, "i2c_transfer" },
	{ 0x8bd94317, "_raw_spin_lock_bh" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0xa0eac20, "seq_printf" },
	{ 0x8861a77d, "remove_proc_entry" },
	{ 0x353e3fa5, "__get_user_4" },
	{ 0xa81e2e1f, "__register_chrdev" },
	{ 0xdcb27b57, "pci_dev_get" },
	{ 0xf0ef15b4, "list_sort" },
	{ 0x7426f76c, "init_timer_key" },
	{ 0x9e2e406c, "mutex_unlock" },
	{ 0x999e8297, "vfree" },
	{ 0xa2487e0, "unblock_all_signals" },
	{ 0x30abef41, "debugfs_create_file" },
	{ 0xb441c94, "idr_for_each" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xbf7b7bec, "seq_read" },
	{ 0x7d11c268, "jiffies" },
	{ 0xda1a7335, "kasprintf" },
	{ 0x41e92619, "__init_waitqueue_head" },
	{ 0xffd5a395, "default_wake_function" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x776ba039, "pci_set_master" },
	{ 0x407136b1, "__put_user_8" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x7bbd7cc2, "pci_get_subsys" },
	{ 0x2d87a8af, "proc_mkdir" },
	{ 0x8f0ed7ad, "idr_destroy" },
	{ 0x27bacea5, "device_register" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0xfd91dbac, "mutex_lock_interruptible" },
	{ 0x34908c14, "print_hex_dump_bytes" },
	{ 0xe66ce648, "__mutex_init" },
	{ 0x27e1a049, "printk" },
	{ 0x42224298, "sscanf" },
	{ 0x71c90087, "memcmp" },
	{ 0x328a05f1, "strncpy" },
	{ 0xb9db7c2f, "fasync_helper" },
	{ 0x92ad529a, "dma_free_coherent" },
	{ 0xdaf4dfb3, "fb_mode_option" },
	{ 0x84b183ae, "strncmp" },
	{ 0xd18ed691, "debugfs_remove" },
	{ 0xbf8ba54a, "vprintk" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x20d67846, "mutex_lock" },
	{ 0xc89cd936, "vga_client_register" },
	{ 0x2374e0e0, "class_remove_file" },
	{ 0xd836bab0, "noop_llseek" },
	{ 0x53985936, "mod_timer" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0xf60330d7, "class_create_file" },
	{ 0x6581abd7, "i2c_unregister_device" },
	{ 0x527ecf54, "up_write" },
	{ 0x33898f38, "down_write" },
	{ 0xf4e43be0, "fput" },
	{ 0x447a7776, "__get_page_tail" },
	{ 0x61ea829e, "shmem_file_setup" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x87e31407, "kobject_uevent_env" },
	{ 0xc0592d66, "dma_alloc_coherent" },
	{ 0x3df1167f, "idr_remove" },
	{ 0x3b030c94, "do_mmap_pgoff" },
	{ 0xb7951ef2, "device_create_file" },
	{ 0x66f4145e, "idr_pre_get" },
	{ 0xc07fdcf2, "module_put" },
	{ 0xc6cbbc89, "capable" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x72733668, "kmem_cache_alloc" },
	{ 0xb303f633, "idr_remove_all" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0xb368ec89, "_raw_spin_unlock_bh" },
	{ 0x5635a60a, "vmalloc_user" },
	{ 0x3adba064, "___dma_page_cpu_to_dev" },
	{ 0xcbce0d96, "schedule" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x8a7d1c31, "high_memory" },
	{ 0x1abe4a7, "___dma_page_dev_to_cpu" },
	{ 0xc27487dd, "__bug" },
	{ 0xa0b04675, "vmalloc_32" },
	{ 0x4b34fbf5, "block_all_signals" },
	{ 0x83b2669e, "pci_unregister_driver" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0x341dbfa3, "__per_cpu_offset" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0x910b4639, "idr_get_new_above" },
	{ 0x72542c85, "__wake_up" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0x6adf4594, "proc_create_data" },
	{ 0x3fdacc6f, "add_wait_queue" },
	{ 0x4784105d, "seq_lseek" },
	{ 0x83800bfa, "kref_init" },
	{ 0x37a0cba, "kfree" },
	{ 0x42231bb6, "remap_pfn_range" },
	{ 0x9d669763, "memcpy" },
	{ 0x32f80ea9, "prepare_to_wait" },
	{ 0x9775cdc, "kref_get" },
	{ 0xca75f269, "sysfs_create_bin_file" },
	{ 0xf001c540, "__pci_register_driver" },
	{ 0x8b494b4c, "idr_replace" },
	{ 0x86626159, "class_destroy" },
	{ 0x45a55ec8, "__iounmap" },
	{ 0xf83178bd, "finish_wait" },
	{ 0xbeac7f79, "dev_warn" },
	{ 0x9771c9c2, "device_unregister" },
	{ 0x40a6f522, "__arm_ioremap" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x82e5a238, "vm_get_page_prot" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0xb95f98d6, "_memset_io" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x5bc366b2, "platform_get_irq" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x6dc96ae3, "vmalloc_to_page" },
	{ 0x8c1e998, "dev_set_name" },
	{ 0xed8aaba2, "idr_init" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0x9a40563d, "pci_enable_device" },
	{ 0xa170bbdb, "outer_cache" },
	{ 0xf60fdde3, "idr_find" },
	{ 0x56303c2f, "__class_create" },
	{ 0xb8053763, "i2c_new_device" },
	{ 0xfc732e8b, "show_class_attr_string" },
	{ 0xb859f38b, "krealloc" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xdf4c8767, "ns_to_timeval" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

