cmd_fs/nfsd/nfsd.ko := ld -EL -r  -T /home/andypugh/git/Kernel_Unico/scripts/module-common.lds --build-id  -o fs/nfsd/nfsd.ko fs/nfsd/nfsd.o fs/nfsd/nfsd.mod.o
