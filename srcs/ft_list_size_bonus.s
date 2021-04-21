section .text
global _ft_list_size

_ft_list_size:
	xor		eax, eax
LOOP:
	cmp		rdi, 0
	je		EXIT
	mov		rdi, QWORD[rdi + 8]
	inc		eax
	jmp		LOOP

EXIT:
	ret
