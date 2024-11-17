global ft_strdup				; Déclaration de la fonction en global

extern ft_strlen				; Appel externe de la fonction ft_strlen
extern ft_strcpy				; Appel externe de la fonction ft_strcpy
extern malloc					; Appel externe de la fonction malloc

ft_strdup:						; Action executées lors du call de la fonction
	xor rax, rax				; Efface le contenu de rax

.execute:						; Label .execute pour executer l'action de ft_strdup
	mov r8, rdi					; Copie de rdi dans r8
	push r8						; Sauvegarde de r8 dans la stack
	call ft_strlen				; Appel de la fonction ft_strlen, résultat mis dans rax
	mov rdi, rax				; Copie de rax dans rdi
	inc rdi						; Incrémentation de rdi pour compter un bit nul (\0)

	call malloc					; Appel de la fonction malloc, résultat mis dans rax
	cmp rax, 0					; Compare rax à 0
	je .end						; Jump conditionnel, si la comparaison précédente est valide, au Label .end

	pop r8						; Récupération de la dernière de la stack donnée dans r8
	mov rdi, rax				; Copie de rax dans rdi
	mov rsi, r8					; Copie de r8 dans rsi
	call ft_strcpy				; Appel de la fonction ft_strcpy, résultat mis dans rax
	jmp .end					; Jump inconditionnel au Label .end

.end:							; Label .end pour executer la fin de ft_strdup
	ret							; Retour de la valeur rax