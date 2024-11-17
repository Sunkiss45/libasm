global ft_strdup;

extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
	xor rax, rax

.execute:
	mov r8, rdi
	push r8
	call ft_strlen
	mov rdi, rax
	inc rdi

	call malloc
	cmp rax, 0
	je .end

	pop r8
	mov rdi, rax
	mov rsi, r8
	call ft_strcpy
	jmp .end

.end:
	ret