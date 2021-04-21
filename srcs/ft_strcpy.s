section .text
global _ft_strcpy

_ft_strcpy:
	xor		rax, rax
LOOP:
	mov		dl, BYTE[rsi + rax]
	mov		BYTE[rdi + rax], dl
	cmp		BYTE[rsi + rax], 0
	je		EXIT
	inc		rax
	jmp		LOOP

EXIT:
	mov		rax, rdi
	ret
