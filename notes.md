supo apt install cscope
sudo apt install universal-ctags


ctags -R

----------
building kernel
- download from https://kernel.org/
- extract
- export LKP_KSRC=~/linux-6.1.93

default configuration:
- make mrproper <- clean evrything
- make defconfig <- generate new default config
use existing config
- lsmod > /tmp/lsmod.now
- cd ${LSK_KSRC}
- make LSMOD=/tmp/lsmod.now localmodconfig


make menuconfig <- build UI program to tune config


scripts/diffconfig .config.old .config <- get config last change

scripts/config <- change config in scriptable way


build:
- make -j4 (from root dir)

- make kernelrelease kernelversion image_name (from root dir) 


install modules:
- sudo make modules_install

generate initramfs:
- sudo make install

GRUB customization
to alweys show GRUP prompt
- /etc/default/grub
- GRUB_HIDDEN_TIMEOUT_QUIET=false 
- GRUB_TIMEOUT_STYLE=menu
- sudo update-grub


------------
load helloworld module
- cd helloworld_lkm
- make
- sudo insmod ./helloworld_lkm.ko


--------
sudo dmesg <- print kernel log buffer   
lsmod <- list loaded kernel modules
sudo rmmod <name> <- unload kernel module

journalctl -b -k --no-pager | tail -n2 <- example of using journalctl to get kernel logs