cmd_fs/cifs/cifs.ko := ld -EL -r  -T /home/andypugh/git/Kernel_Unico/scripts/module-common.lds --build-id  -o fs/cifs/cifs.ko fs/cifs/cifs.o fs/cifs/cifs.mod.o
