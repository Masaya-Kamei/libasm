section .text
global	_ft_list_push_front
extern	_malloc

_ft_create_elem:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	mov		QWORD[rbp - 8], rdi
	mov		rdi, 16
	call	_malloc
	cmp		rax, 0
	je		EXIT_CREATE_ELEM
	mov		rdi, QWORD[rbp - 8]
	mov		QWORD[rax], rdi
	mov		QWORD[rax + 8], 0
EXIT_CREATE_ELEM:
	leave
	ret


_ft_list_push_front:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	cmp		rdi, 0
	je		EXIT
	mov		QWORD[rbp - 8], rdi
	mov		rdi, rsi
	call	_ft_create_elem
	cmp		rax, 0
	je		EXIT
	mov		rdi, QWORD[rbp - 8]
	mov		rdi, QWORD[rdi]
	mov		QWORD[rax + 8], rdi
	mov		rdi, QWORD[rbp - 8]
	mov		QWORD[rdi], rax
EXIT:
	leave
	ret
