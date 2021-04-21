section .text
global _ft_strcmp

_ft_strcmp:
	xor		rax, rax
LOOP:
	mov		dl, BYTE[rdi + rax]
	mov		cl, BYTE[rsi + rax]
	cmp		dl, cl
	jb		LITTLE
	ja		GREATER
	cmp		BYTE[rdi + rax], 0
	je		EQUAL
	inc		rax
	jmp		LOOP

LITTLE:
	mov		eax, -1
	ret

EQUAL:
	xor		eax, eax
	ret

GREATER:
	mov		eax, 1
	ret
