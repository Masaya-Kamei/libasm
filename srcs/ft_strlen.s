section .text
global _ft_strlen

_ft_strlen:
	xor		rax, rax
LOOP:
	cmp		BYTE[rdi + rax], 0
	je		EXIT
	inc		rax
	jmp		LOOP

EXIT:
	ret
