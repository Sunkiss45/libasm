global ft_strcpy				; Déclaration de la fonction en global

ft_strcpy:						; Action executées lors du call de la fonction
	xor rax, rax				; Efface le contenu de rax
	mov rax, rdi				; Pointe rax sur rdi (chaine de destination fournis)

.loop:							; Label .loop pour executer l'action de ft_strcpy
	mov r8b, [rsi]				; Copie l'acctuel char de rsi dans r8b
	cmp r8b, 0					; Compare r8b à 0 (\0)
	je .end						; Jump conditionnel, si la comparaison précédente est positive, au Label .end
	mov [rdi], r8b				; Implementation de r8b dans l'acctuel char de rdi

	inc rsi						; Déplacement dans la chaine rsi en incrémentation
	inc rdi						; Déplacement dans la chaine rdi en incrémentation
	jmp .loop					; Jump inconditionnel au Label .loop

.end:							; Label .end pour executer la fin de ft_strcpy
	mov byte [rdi], 0			; Implementation de l'octet nul (\0) a la fin de la chaine de retour
	ret							; Retour de la valeur rax