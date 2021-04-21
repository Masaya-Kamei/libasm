section .text
global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	mov		QWORD[rbp - 8], rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc
	cmp		rax, 0
	je		EXIT
	mov		rdi, rax
	mov		rsi, QWORD[rbp - 8]
	call	_ft_strcpy
EXIT:
	leave
	ret
