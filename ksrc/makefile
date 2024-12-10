B=../BareMetal-OS
#CFLAGS=-Ofast -fno-builtin -funsigned-char -fno-unwind-tables -Wno-parentheses -Wno-incompatible-pointer-types -Wfatal-errors -nostdlib -mno-red-zone -mcmodel=large -fomit-frame-pointer -march=cannonlake -I$B/src/BareMetal/api
CFLAGS=-g -fno-builtin -funsigned-char -fno-unwind-tables -Wno-parentheses -Wno-incompatible-pointer-types -Wfatal-errors -nostdlib -mno-red-zone -mcmodel=large -fomit-frame-pointer -march=cannonlake -I$B/src/BareMetal/api
CC=$(shell which clang-13 clang |head -1)
l=-z max-page-size=0x1000
img=$B/sys/baremetal_os.img
app=$B/sys/k.app
rlwrap=$(shell which rlwrap)

all:$(img)
pf/pf.h:
	git clone https://github.com/kparc/pf.git
dbg.o:pf/pf.h
s.o:s.asm
	nasm -f elf64 s.asm
$(app):crt0.o dbg.o a.o z.o s.o makefile
	ld -T app.ld $l crt0.o dbg.o a.o z.o s.o -o k
	objcopy -O binary k $(app)
$(img):$(app)
	cd $B && ./baremetal.sh k.app
bochs:$(img)
	$(rlwrap) bochs -n -q boot:disk ata0-master:type=disk,path=$(img) cpu:model=sapphire_rapids megs:1200
disasm:
	objdump -drwC -Mintel -S k | less
clean:
	rm -rf pf k *.o $(img) $(app)
