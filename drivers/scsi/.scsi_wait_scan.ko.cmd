cmd_drivers/scsi/scsi_wait_scan.ko := ld -EL -r  -T /home/andypugh/git/Kernel_Unico/scripts/module-common.lds --build-id  -o drivers/scsi/scsi_wait_scan.ko drivers/scsi/scsi_wait_scan.o drivers/scsi/scsi_wait_scan.mod.o