section .text
global _ft_list_sort
extern _ft_list_size

_swap_list_data:
	mov		r10, QWORD[rdi]
	mov		r11, QWORD[rsi]
	mov		QWORD[rdi], r11
	mov		QWORD[rsi], r10
	ret

_ft_list_sort:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 32
	cmp		rdi, 0
	je		EXIT
	cmp		rsi, 0
	je		EXIT
	mov		QWORD[rbp - 8], rdi
	mov		QWORD[rbp - 16], rsi
	mov		rdi, QWORD[rdi]
	call	_ft_list_size
	sub		eax, 1
	mov		DWORD[rbp - 20], eax
LOOP1:
	cmp		DWORD[rbp - 20], 0
	jle		EXIT
	mov		r10, QWORD[rbp - 8]
	mov		r10, QWORD[r10]
	mov		QWORD[rbp - 28], r10
	mov		DWORD[rbp - 32], 0
LOOP2:
	mov		r10, QWORD[rbp - 28]
	mov		r11d, DWORD[rbp - 32]
	cmp		r11d, DWORD[rbp - 20]
	jge		AFTER_LOOP2
	mov		rdi, QWORD[r10]
	mov		rsi, QWORD[r10 + 8]
	mov		rsi, QWORD[rsi]
	mov		rdx, QWORD[rbp - 16]
	call	rdx
	cmp		eax, 0
	jle		AFTER_SWAP
	mov		rdi, QWORD[rbp - 28]
	mov		rsi, QWORD[rdi + 8]
	call	_swap_list_data
AFTER_SWAP:
	mov		r10, QWORD[rbp - 28]
	mov		r10, QWORD[r10 + 8]
	mov		QWORD[rbp - 28], r10
	inc		DWORD[rbp - 32]
	jmp		LOOP2
AFTER_LOOP2:
	sub		DWORD[rbp - 20], 1
	jmp		LOOP1

EXIT:
	leave
	ret
