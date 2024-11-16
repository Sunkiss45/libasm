global ft_strcmp				; Déclaration de la fonction en global

ft_strcmp:						; Action executées lors du call de la fonction
	xor rax, rax				; Mise à 0 de rax

.loop:							; Label .loop pour executer l'action de ft_strcmp
	mov r8b, [rdi]				; Copie l'actuel char de rdi dans r8b
	mov r9b, [rsi]				; Copie l'actuel char de rsi dans r9b

	cmp r8b, r9b				; Compare r8b et r9b entre eux
	jne .end					; Jump conditionel, si la comparaison précédente est inégale, au Label .end
	cmp r8b, 0					; Compare r8b et un bit nul (\0)
	je .end						; Jump conditionel, si la comparaison précédente est valide, au Label .end
	cmp r9b, 0					; Compare r9b et un bit nul (\0)
	je .end						; Jump conditionel, si la comparaison précédente est valide, au Label .end

	inc rdi						; Déplacement dans la chaine rdi en incrémentation
	inc rsi						; Déplacement dans la chaine rsi en incrémentation
	jmp .loop					; Jump inconditionel au Label .loop

.end:							; Label .end pour executer la fin de ft_strcmp
	movzx rax, r8b				; Copie de r8b dans rax (movzx permet de rentrer un petit registre dans un grand)
	movzx r10, r9b				; Copie de r9b dans r10 (movzx permet de rentrer un petit registre dans un grand)
	sub rax, r10				; Soustrait rax a r10 pour avoir la valeur ASCII de la différence (0 si identique)
	ret							; Retour de la valeur rax