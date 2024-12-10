OUTPUT_ARCH("i386:x86-64")
ENTRY(_start)
SECTIONS
{
	. = 0xFFFF800000000000;
	.text : {
		*(.text.startup)
		*(.text)
	}
	.data : {
		*(.data .rodata) QUAD(ADDR(.bss)+SIZEOF(.bss))
	}
	.bss : {
		__bss_start = .;
		*(.bss)
		__bss_stop = .;
	}
}

