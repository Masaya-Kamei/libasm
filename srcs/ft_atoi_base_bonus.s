section .text
global _ft_atoi_base
extern _ft_strlen

;-----------------------------------------------------------------
_ft_strchr:
	xor		r11, r11
	jmp		LOOP_FT_STRCHR
LOOP_FT_STRCHR:
	cmp		BYTE[rdi + r11], 0
	je		NOTFOUND_FT_STRCHR
	cmp		BYTE[rdi + r11], sil
	je		FOUND_FT_STRCHR
	inc		r11
	jmp		LOOP_FT_STRCHR

FOUND_FT_STRCHR:
	mov		rax, rdi
	add		rax, r11
	ret

NOTFOUND_FT_STRCHR:
	xor		rax, rax
	ret

;-----------------------------------------------------------------
_check_base:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	mov		QWORD[rbp - 8], rdi
	mov		DWORD[rbp - 12], 0
	jmp		LOOP_CHECK_BASE

LOOP_CHECK_BASE:
	mov		r10, QWORD[rbp - 8]
	movsxd	r11, DWORD[rbp - 12]
	cmp		BYTE[r10 + r11], 0
	je		EXIT_CHECK_BASE
	cmp		BYTE[r10 + r11], 9
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 10
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 11
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 12
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 13
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 32
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 43
	je		ERROR_CHECK_BASE
	cmp		BYTE[r10 + r11], 45
	je		ERROR_CHECK_BASE
	mov		rdi, r10
	add		rdi, r11
	add		rdi, 1
	mov		sil, BYTE[r10 + r11]
	call	_ft_strchr
	cmp		rax, 0
	jne		ERROR_CHECK_BASE
	inc		DWORD[rbp - 12]
	jmp		LOOP_CHECK_BASE

ERROR_CHECK_BASE:
	xor		eax, eax
	leave
	ret

EXIT_CHECK_BASE:
	cmp		DWORD[rbp - 12], 1
	jle		ERROR_CHECK_BASE
	mov		eax, 1
	leave
	ret

;-----------------------------------------------------------------
_get_int_from_base_str:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 32
	mov		QWORD[rbp - 8], rdi
	mov		QWORD[rbp - 16], rsi
	mov		DWORD[rbp - 20], 0
	mov		DWORD[rbp - 24], 0
	mov		rdi, QWORD[rbp - 16]
	call	_ft_strlen
	mov		DWORD[rbp - 28], eax
	jmp		LOOP_GET_INT

LOOP_GET_INT:
	mov		r10, QWORD[rbp - 8]
	movsx	r11, DWORD[rbp - 20]
	cmp		BYTE[r10 + r11], 0
	je		EXIT_GET_INT
	mov		rdi, QWORD[rbp - 16]
	mov		sil, BYTE[r10 + r11]
	call	_ft_strchr
	cmp		rax, 0
	je		EXIT_GET_INT
	mov		edx, DWORD[rbp - 24]
	imul	edx, DWORD[rbp - 28]
	sub		rax, QWORD[rbp - 16]
	add		edx, eax
	mov		DWORD[rbp - 24], edx
	inc		DWORD[rbp - 20]
	jmp		LOOP_GET_INT

EXIT_GET_INT:
	mov		eax, DWORD[rbp - 24]
	leave
	ret

;-----------------------------------------------------------------
_ft_atoi_base:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 32
	cmp		rdi, 0
	je		ERROR_ATOI_BASE
	cmp		rsi, 0
	je		ERROR_ATOI_BASE
	mov		QWORD[rbp - 8], rdi
	mov		QWORD[rbp - 16], rsi
	mov		DWORD[rbp - 20], 0
	mov		rdi, QWORD[rbp - 16]
	call	_check_base
	cmp		eax, 0
	je		ERROR_ATOI_BASE
	mov		r10, QWORD[rbp - 8]
	xor		r11, r11
	jmp		LOOP_SPACE

LOOP_SPACE:
	cmp		BYTE[r10 + r11], 9
	je		INC_INDEX_1
	cmp		BYTE[r10 + r11], 10
	je		INC_INDEX_1
	cmp		BYTE[r10 + r11], 11
	je		INC_INDEX_1
	cmp		BYTE[r10 + r11], 12
	je		INC_INDEX_1
	cmp		BYTE[r10 + r11], 13
	je		INC_INDEX_1
	cmp		BYTE[r10 + r11], 32
	je		INC_INDEX_1
	jmp		LOOP_PLUSMINUS
INC_INDEX_1:
	inc		r11
	jmp		LOOP_SPACE

LOOP_PLUSMINUS:
	cmp		BYTE[r10 + r11], 43
	je		INC_INDEX_2
	cmp		BYTE[r10 + r11], 45
	je		INC_MINUS
	jmp		GET_INT_FROM_BASE_STR
INC_MINUS:
	inc		DWORD[rbp - 20]
	cmp		DWORD[rbp - 20], 1
	je		INC_INDEX_2
	mov		DWORD[rbp - 20], 0
INC_INDEX_2:
	inc		r11
	jmp		LOOP_PLUSMINUS

GET_INT_FROM_BASE_STR:
	mov		rdi, r10
	add		rdi, r11
	mov		rsi, QWORD[rbp - 16]
	call	_get_int_from_base_str
	cmp		eax, 0
	je		EXIT_ATOI_BASE
	cmp		DWORD[rbp - 20], 0
	je		EXIT_ATOI_BASE
	imul	eax, -1
	jmp		EXIT_ATOI_BASE

ERROR_ATOI_BASE:
	xor		eax, eax
	leave
	ret

EXIT_ATOI_BASE:
	leave
	ret
