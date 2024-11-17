global ft_strlen					; Déclaration de la fonction en global

ft_strlen:							; Action executées lors du call de la fonction
	xor rax, rax					; Efface le contenu de rax

.loop:								; Label .loop pour executer l'action de ft_strlen
	cmp byte [rdi + rax], 0			; Comparaison de l'address pointé a l'octet (byte) rdi+rax à un 0 (/0)
	je .end							; Jump conditionnel, si la comparaison précédente est positive, au Label .end
	inc rax							; Incrémentation de la valeur rax
	jmp .loop						; Jump inconditionnel au Label .loop

.end:								; Label .end pour executer la fin de ft_strlen
	ret								; Retour de la valeur rax