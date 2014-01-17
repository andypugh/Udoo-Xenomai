cmd_drivers/bluetooth/built-in.o :=  ld -EL    -r -o drivers/bluetooth/built-in.o drivers/bluetooth/hci_vhci.o drivers/bluetooth/hci_uart.o drivers/bluetooth/btusb.o 
