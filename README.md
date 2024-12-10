This port was created by [Jack Andrews](https://github.com/effbiae)

# k on BareMetal

This repo is a port of [k edu](https://shakti.com/) to the
[BareMetal](https://github.com/ReturnInfinity/BareMetal-OS) operating system.
At this stage, it is just a proof of concept and doesn't integrate the
BareMetal file system.

## why k on BareMetal-OS?
The BareMetal-OS philosophy aligns with k - it's only 16KB and does just enough.
It provides raw access to ethernet and disk and everything runs in ring 0.

## just tell me what to do
### make a directory to play in
```
mkdir sandbox; cd sandbox
```
The following instructions assume you're on a Debian based system. `apt-get install` means install package, so you can translate that to your system.
### build BareMetal-OS
```
sudo apt-get install nasm gcc git mtools
git clone https://github.com/ReturnInfinity/BareMetal-OS.git
cd BareMetal-OS && ./baremetal.sh setup && cd ..
```
If you want to copy k to hard disk and boot that disk, skip to [build k](#build-k).
But you probably want to emulate hardware, so build bochs, a pc emulator that supports avx512.

### build bochs 2.8
```
# optionally,  sudo apt-get install libgtk-3-dev  for bochs gui debugger
wget https://sourceforge.net/projects/bochs/files/bochs/2.8/bochs-2.8.tar.gz
tar xf bochs-2.8.tar.gz
cd bochs-2.8
./configure --enable-smp --enable-cpu-level=6 --enable-all-optimizations --enable-x86-64 --enable-pci --enable-usb --enable-vmx --enable-debugger --enable-disasm --enable-debugger-gui --enable-logging --enable-fpu --enable-3dnow --enable-sb16=dummy --enable-cdrom --enable-x86-debugger --enable-iodebug --disable-plugins --disable-docbook --with-x --with-x11 --with-term --enable-avx --enable-evex
make
sudo make install
cd ..
``` 
### build k
```
sudo apt-get install clang nasm
git clone https://github.com/ReturnInfinity/kbm.git
cd kbm
make
```
If you want to copy k to hard disk and boot that disk, skip to [if you want to run it on hardware](#if-you-want-to-run-it-on-hardware)

### run k in bochs
now `make bochs` will start the bochs emulator.
 - after a few seconds, a window will appear
 - switch back to the console
    * you will see a `<bochs>` prompt
 - at the prompt, type `c` to continue
    * bochs starts emulation and in a few seconds the window will let you interact with k
 - to quit, exit k with \\\\

### if you want to run it on hardware
> [!CAUTION]
> Doublecheck that you are writing the disk image to the correct disk

```
dd if=../sandbox/BareMetal-OS/sys/baremetal_os.img of=/dev/sdc
```
and boot from that disk
