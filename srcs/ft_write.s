global ft_write

extern __errno_location

ft_write:
	xor rax, rax

.execute:
	mov rax, 1
	syscall
	cmp rax, 0
	jl .error
	jmp .end

.error:
	neg rax
	mov r8, rax
	call __errno_location
	mov [rax], r8
	mov rax, -1
	ret

.end:
	ret