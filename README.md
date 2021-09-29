# basic-kernel-module
Template for creating Linux Kernel Modules.  

## Generate the Makefile
This example utilizes the *genmake* script, provided by the Linux Foundation and used in a number of their training courses. This script examines the development environment and generates a Makefile configured to work with the running kernel.

```
student@entre-nous:~/basic-kernel-module/example_mod$ ./genmake 
KROOT = /lib/modules/5.4.0-84-generic/build, Kernel Makefile = /lib/modules/5.4.0-84-generic/build/Makefile
K_S= example_mod.c OBJS= example_mod.o U_S= U_X= T_S= T_X=
student@entre-nous:~/basic-kernel-module/example_mod$ ls
example_mod.c  genmake  Makefile
```

## Build the Kernel Module
The generated Makefile works hand-in-hand with the kernel build system to build this kernel module outside of the kernel tree

```
make
make[1]: Entering directory '/usr/src/linux-headers-5.4.0-84-generic'
  CC [M]  /home/student/basic-kernel-module/example_mod/example_mod.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC [M]  /home/student/basic-kernel-module/example_mod/example_mod.mod.o
  LD [M]  /home/student/basic-kernel-module/example_mod/example_mod.ko
make[1]: Leaving directory '/usr/src/linux-headers-5.4.0-84-generic'
```

## Load the Kernel Module
To test the kernel module, you can load it using *insmod*.  You can view the test message by examining the *dmesg* output

```
student@entre-nous:~/basic-kernel-module/example_mod$  sudo insmod example_mod.ko
[sudo] password for student: 
student@entre-nous:~/basic-kernel-module/example_mod$ dmesg | tail -1
[ 7810.274219] Module Loaded
```

## Unload the Kernel Module
To unload the kernel module, us *rmmod*.


```
student@entre-nous:~/basic-kernel-module/example_mod$ sudo rmmod example_mod 
student@entre-nous:~/basic-kernel-module/example_mod$ dmesg | tail -1
[ 7948.087314] Module Unloaded
```