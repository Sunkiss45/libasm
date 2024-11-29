global ft_atoi_base

extern __errno_location			; Appel externe de la fonction __errno_location

ft_atoi_base:					; rdi = chaine / rsi = base
	xor rax, rax
	jmp .checker_base

.base_error:					; Label en cas d'erreur dans la base
	call __errno_location		; retour 0 et set de errno
	mov [rax], 22
	mov rax, 0
	ret							; ===

.checker_base:

	cmp [rsi], 0				; Bloc permettant de regarder si la base
	je .base_error				; donnée fais 0 ou 1 de taille
	mov r8b, [rsi]				; Auquelle cas, jump à error
	inc r8b
	cmp r8b, 0
	je .base_error				; ===

	mov r8, rsi
	jmp .whitespace

.loop_whitespace:
	inc r8
	jmp .whitespace

.whitespace:
	cmp [r8], 9
	jl .
	cmp [r8], 32
	je .
	cmp [r8], 13
	jg .
	jmp loop_whitespace