cmd_security/built-in.o :=  ld -EL    -r -o security/built-in.o security/keys/built-in.o security/commoncap.o security/min_addr.o security/device_cgroup.o 
