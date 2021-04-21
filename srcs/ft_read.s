section .text
global _ft_read
extern	___error

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		ERROR_READ
	ret

ERROR_READ:
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
