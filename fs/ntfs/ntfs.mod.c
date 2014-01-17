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
	{ 0xff013b18, "__kmap_atomic" },
	{ 0xec7d4346, "kmem_cache_destroy" },
	{ 0x3dbd9bc9, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x6705cf67, "sb_min_blocksize" },
	{ 0xff178f6, "__aeabi_idivmod" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x85b87d7c, "up_read" },
	{ 0x54b425e9, "__bread" },
	{ 0xedcc74f8, "unload_nls" },
	{ 0x3fa00eb8, "make_bad_inode" },
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0x76c55c20, "generic_file_llseek" },
	{ 0x7604b521, "__mark_inode_dirty" },
	{ 0xeab2abe4, "__set_page_dirty_nobuffers" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x349cba85, "strchr" },
	{ 0xaa253ee, "generic_write_checks" },
	{ 0xf5c9012e, "timespec_trunc" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x97255bdf, "strlen" },
	{ 0xd442b3f4, "_raw_write_lock_irqsave" },
	{ 0x26f9c4da, "__ipipe_test_and_stall_root" },
	{ 0x15e50ef1, "page_address" },
	{ 0xcf291301, "iget5_locked" },
	{ 0x5fb28fb8, "end_buffer_write_sync" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x9bc8795b, "block_invalidatepage" },
	{ 0x85c0fd15, "generic_fh_to_parent" },
	{ 0x16a45a95, "grab_cache_page_nowait" },
	{ 0x67053080, "current_kernel_time" },
	{ 0xfc2c1dcf, "is_bad_inode" },
	{ 0xab27825c, "generic_file_open" },
	{ 0x4ed6e5ba, "test_set_page_writeback" },
	{ 0xd7ca74f6, "__lock_page" },
	{ 0x4d328a16, "__lock_buffer" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x123ca2a5, "generic_file_aio_read" },
	{ 0x2a3aa678, "_test_and_clear_bit" },
	{ 0xa0eac20, "seq_printf" },
	{ 0x40b2d351, "buffer_migrate_page" },
	{ 0x333eae0e, "add_to_page_cache_lru" },
	{ 0x85360c39, "end_writeback" },
	{ 0x9e2e406c, "mutex_unlock" },
	{ 0x6d932dd2, "mount_bdev" },
	{ 0x85df9b6c, "strsep" },
	{ 0xd37de5c2, "generic_read_dir" },
	{ 0x999e8297, "vfree" },
	{ 0x56bb933d, "igrab" },
	{ 0x1251d30f, "call_rcu" },
	{ 0x7f0df292, "unlock_buffer" },
	{ 0x8aaa5294, "generic_write_sync" },
	{ 0x8d48663, "redirty_page_for_writepage" },
	{ 0x4728e7, "__alloc_pages_nodemask" },
	{ 0xeebda262, "set_page_dirty" },
	{ 0x79a0c717, "mutex_trylock" },
	{ 0x1907c2a2, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x77339464, "_raw_write_unlock_irqrestore" },
	{ 0xe54b1ed1, "end_page_writeback" },
	{ 0xde9360ba, "totalram_pages" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0xa8df9427, "__insert_inode_hash" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x5f754e5a, "memset" },
	{ 0xcd63c845, "__aeabi_lasr" },
	{ 0x4e3fd1f4, "d_add_ci" },
	{ 0xd79878a4, "current_fs_time" },
	{ 0xe66ce648, "__mutex_init" },
	{ 0x27e1a049, "printk" },
	{ 0x652a8d8f, "d_rehash" },
	{ 0x8d351be, "find_lock_page" },
	{ 0x4d8c3097, "d_obtain_alias" },
	{ 0x71c90087, "memcmp" },
	{ 0x107df04f, "write_inode_now" },
	{ 0xcbdd12c4, "find_or_create_page" },
	{ 0xdefe2383, "d_alloc_root" },
	{ 0x65d37637, "__ipipe_restore_root" },
	{ 0x1a5888a7, "kunmap" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x36f79b8a, "ilookup5_nowait" },
	{ 0xf073ccc9, "kmem_cache_free" },
	{ 0x93a6e0b2, "io_schedule" },
	{ 0x20d67846, "mutex_lock" },
	{ 0x98b97505, "file_remove_suid" },
	{ 0x87613201, "__wait_on_buffer" },
	{ 0x2d34ad2a, "file_update_time" },
	{ 0xed93f29e, "__kunmap_atomic" },
	{ 0xad1ef10f, "sync_dirty_buffer" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0x11dbf866, "unlock_page" },
	{ 0x527ecf54, "up_write" },
	{ 0x33898f38, "down_write" },
	{ 0x447a7776, "__get_page_tail" },
	{ 0xfc291ecb, "__brelse" },
	{ 0xba31ddb0, "contig_page_data" },
	{ 0x3db0382f, "ilookup5" },
	{ 0xb7509d49, "mark_page_accessed" },
	{ 0xb36cc436, "mark_buffer_async_write" },
	{ 0x6cdf66c, "balance_dirty_pages_ratelimited_nr" },
	{ 0x15ddcad7, "inode_init_once" },
	{ 0x72733668, "kmem_cache_alloc" },
	{ 0xaca37af7, "_raw_read_lock_irqsave" },
	{ 0xa1ebda84, "generic_file_mmap" },
	{ 0x4948e52a, "kmap" },
	{ 0xd4b1d099, "free_buffer_head" },
	{ 0xfdf3383b, "sync_blockdev" },
	{ 0x1afa96fe, "create_empty_buffers" },
	{ 0xd372b780, "load_nls" },
	{ 0xcbce0d96, "schedule" },
	{ 0x8a7d1c31, "high_memory" },
	{ 0xeb9e32a2, "do_sync_read" },
	{ 0x7fbb1f14, "unlock_new_inode" },
	{ 0x456dde34, "kill_block_super" },
	{ 0xa882d544, "_raw_read_unlock_irqrestore" },
	{ 0xc27487dd, "__bug" },
	{ 0xe68c2b91, "unmap_underlying_metadata" },
	{ 0x83221266, "inode_change_ok" },
	{ 0xe74b6c9, "submit_bh" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0x6a3a240b, "kmem_cache_create" },
	{ 0x629873dd, "register_filesystem" },
	{ 0x57a6504e, "vsnprintf" },
	{ 0x952c4e4, "iput" },
	{ 0x26477c07, "__vmalloc" },
	{ 0xc346720, "read_cache_page" },
	{ 0x37a0cba, "kfree" },
	{ 0xd362f333, "do_sync_write" },
	{ 0xa54bc297, "ihold" },
	{ 0x9d669763, "memcpy" },
	{ 0x32f80ea9, "prepare_to_wait" },
	{ 0x49324df8, "load_nls_default" },
	{ 0xc122294f, "generic_error_remove_page" },
	{ 0xa13a52fb, "d_splice_alias" },
	{ 0xc000cf3f, "end_buffer_read_sync" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x77dc2412, "vmtruncate" },
	{ 0x800da2ff, "sb_set_blocksize" },
	{ 0x8b184d6c, "put_page" },
	{ 0x38e8378d, "pgprot_kernel" },
	{ 0xf83178bd, "finish_wait" },
	{ 0x4cbbd171, "__bitmap_weight" },
	{ 0x75ba2aff, "mark_buffer_dirty" },
	{ 0xec41c7f5, "unregister_filesystem" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xf5c05914, "generic_segment_checks" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x2f3306ca, "new_inode" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x99bb8806, "memmove" },
	{ 0x9093e2b2, "generic_file_splice_read" },
	{ 0x3e377e9d, "__getblk" },
	{ 0x8a4fa83b, "__aeabi_llsr" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0x25a6852c, "generic_fh_to_dentry" },
	{ 0xa170bbdb, "outer_cache" },
	{ 0x27021e0f, "d_instantiate" },
	{ 0x5c4d8bf, "__init_rwsem" },
	{ 0xa2feb511, "flush_dcache_page" },
	{ 0x281b4620, "alloc_page_buffers" },
	{ 0xd9494d16, "truncate_inode_pages" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "66B54D6F1AAE2DE802EA227");
