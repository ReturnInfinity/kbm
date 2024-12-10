# change B to the path to BareMetal-OS
B=../BareMetal-OS
CFLAGS=-Ofast -fno-builtin -funsigned-char -fno-unwind-tables -Wno-parentheses -Wno-incompatible-pointer-types \
       -Wfatal-errors -nostdlib -mno-red-zone -mcmodel=large -fomit-frame-pointer \
       -march=icelake-client -I$B/src/BareMetal/api
CC=$(shell which clang-13 clang |head -1)
l=-z max-page-size=0x1000 -z noexecstack
img=$B/sys/baremetal_os.img
app=$B/sys/k.app

all:$(img)
_.h: makefile
	cp ksrc/*.[hc] .
z.c:_.h
a.c:_.h
s.o:s.asm
	nasm -f elf64 s.asm -I$B/src/BareMetal
$(img):sys.o a.o z.o s.o
	ld -T app.ld $l sys.o a.o z.o s.o -o k
	objcopy -O binary k $(app)
	cd $B && ./baremetal.sh k.app
bochs:$(img)
	bochs -n -q boot:disk ata0-master:type=disk,path=$(img) cpu:model=sapphire_rapids megs:1200
disasm:
	objdump -drwC -Mintel -S k | less
clean:
	rm -rf k *.o *.s $(img) $(app) ?.[ch] z.k bochsrc
