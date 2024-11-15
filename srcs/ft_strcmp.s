global ft_strcmp

ft_strcmp:
	xor rax, rax

.loop:
	mov r8b, [rdi]
	mov r9b, [rsi]
	cmp r8b, r9b
	je .end
	inc rdi
	inc rsi
	jmp .end

.end:
	mov r8b, [rdi]
	sub r8b, [rsi]
	movzx rax, r8b
	ret