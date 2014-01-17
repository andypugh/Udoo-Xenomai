cmd_drivers/ata/built-in.o :=  ld -EL    -r -o drivers/ata/built-in.o drivers/ata/libata.o drivers/ata/ahci.o drivers/ata/libahci.o drivers/ata/ahci_platform.o 
