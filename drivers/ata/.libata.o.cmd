cmd_drivers/ata/libata.o := ld -EL    -r -o drivers/ata/libata.o drivers/ata/libata-core.o drivers/ata/libata-scsi.o drivers/ata/libata-eh.o drivers/ata/libata-transport.o drivers/ata/libata-sff.o 