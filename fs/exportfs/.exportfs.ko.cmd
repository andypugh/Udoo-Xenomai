cmd_fs/exportfs/exportfs.ko := ld -EL -r  -T /home/andypugh/git/Kernel_Unico/scripts/module-common.lds --build-id  -o fs/exportfs/exportfs.ko fs/exportfs/exportfs.o fs/exportfs/exportfs.mod.o
