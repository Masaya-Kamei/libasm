section .text
global _ft_list_remove_if
extern _free

_ft_list_remove_if:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 48
	cmp		rdi, 0
	je		EXIT
	cmp		rsi, 0
	je		EXIT
	cmp		rdx, 0
	je		EXIT
	cmp		rcx, 0
	je		EXIT
	mov		QWORD[rbp - 8], rdi
	mov		QWORD[rbp - 16], rsi
	mov		QWORD[rbp - 24], rdx
	mov		QWORD[rbp - 32], rcx
	mov		QWORD[rbp - 40], 0
	mov		rdi, QWORD[rdi]
	mov		QWORD[rbp - 48], rdi
LOOP:
	cmp		QWORD[rbp - 48], 0
	je		EXIT
	mov		rdi, QWORD[rbp - 48]
	mov		rdi, QWORD[rdi]
	mov		rsi, QWORD[rbp - 16]
	mov		rdx, QWORD[rbp - 24]
	call	rdx
	cmp		eax, 0
	jne		NO_REMOVE
	cmp		QWORD[rbp - 40], 0
	jne		CONNECT_PREV_NEXT
CONNECT_BEGIN:
	mov		rdi, QWORD[rbp - 48]
	mov		rdi, QWORD[rdi + 8]
	mov		rsi, QWORD[rbp - 8]
	mov		QWORD[rsi], rdi
	jmp		AFTER_CONNECT
CONNECT_PREV_NEXT:
	mov		rdi, QWORD[rbp - 48]
	mov		rdi, QWORD[rdi + 8]
	mov		rsi, QWORD[rbp - 40]
	mov		QWORD[rsi + 8], rdi
AFTER_CONNECT:
	mov		rdi, QWORD[rbp - 48]
	mov		rdi, QWORD[rdi]
	mov		rsi, QWORD[rbp - 32]
	call	rsi
	mov		rdi, QWORD[rbp - 48]
	call	_free
	cmp		QWORD[rbp - 40], 0
	jne		LIST_EQUAL_PREV_NEXT
LIST_EQUAL_BEGIN:
	mov		rdi, QWORD[rbp - 8]
	mov		rdi, QWORD[rdi]
	mov		QWORD[rbp - 48], rdi
	jmp		AFTER_UPDATE_LIST
LIST_EQUAL_PREV_NEXT:
	mov		rdi, QWORD[rbp - 40]
	mov		rdi, QWORD[rdi + 8]
	mov		QWORD[rbp - 48], rdi
AFTER_UPDATE_LIST:
	jmp		LOOP

NO_REMOVE:
	mov		rdi, QWORD[rbp - 48]
	mov		QWORD[rbp - 40], rdi
	mov		rdi, QWORD[rdi + 8]
	mov		QWORD[rbp - 48], rdi
	jmp		LOOP

EXIT:
	leave
	ret
