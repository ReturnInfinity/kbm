; BareMetal Linux syscall translation
; x86-64 passes syscall arguments as follows:
; SC	RETURN	ARG0	ARG1	ARG2	ARG3	ARG4	ARG5
; RAX	RAX	RDI	RSI	RDX	R10	R8	R9

; -----------------------------------------------------------------------------
; b_k -- BareMetal Linux syscall API for k
global b_k
extern input_read
b_k:
	cmp ax, 0
	je b_k_read_stdin
	cmp ax, 1
	je b_k_write_stdout
	mov rax,$-1
	ret
b_k_read_stdin:
	call input_read
	ret
b_k_write_stdout:
	push rcx
	mov rcx, rdx
	call [0x00100018]		; b_output
	pop rcx
	mov rax, rdx
	ret
;-----------------------------------------------------------------------------
