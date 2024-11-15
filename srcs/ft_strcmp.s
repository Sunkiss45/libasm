global ft_strcmp

ft_strcmp:
	xor rax, rax

.loop:
	mov r8b, [rdi]
	mov r9b, [rsi]
	cmp r8b, r9b
	jne .end
	cmp r8b, 0
	je .end
	cmp r9b, 0
	je .end
	inc rdi
	inc rsi
	jmp .loop

.end:
	movzx rax, r8b
	movzx r10, r9b
	sub rax, r10
	ret