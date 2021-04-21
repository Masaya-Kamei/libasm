section .text
global _ft_write
extern	___error

_ft_write:
	mov		rax, 0x2000004
	syscall
	jc		ERROR_WRITE
	ret

ERROR_WRITE:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	mov		QWORD[rbp - 8], rax
	call	___error
	mov		r10, QWORD[rbp - 8]
	mov		QWORD[rax], r10
	mov		rax, -1
	leave
	ret
