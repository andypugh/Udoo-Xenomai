cmd_drivers/mtd/nand/built-in.o :=  ld -EL    -r -o drivers/mtd/nand/built-in.o drivers/mtd/nand/nand.o drivers/mtd/nand/nand_ecc.o drivers/mtd/nand/nand_ids.o drivers/mtd/nand/gpmi-nand/built-in.o 
