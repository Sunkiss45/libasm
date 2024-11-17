global ft_write					; Déclaration de la fonction en global

extern __errno_location			; Appel externe de la fonction __errno_location

ft_write:						; Action executées lors du call de la fonction
	xor rax, rax				; Efface le contenu de rax

.execute:						; Label .execute pour executer l'action de ft_write
	mov rax, 1					; Mise à 1 de rax
	syscall						; Appel systeme de la fonction sys->rax, rax = 1 donc write
	cmp rax, 0					; Comparaison de rax à 0
	jl .error					; Jump conditionnel, si la comparaison précédente contient arg-1 plus petit que arg-2, au Label .error
	jmp .end					; Jump inconditionnel au Label .end

.error:							; Label .error pour gérer les cas d'erreur de ft_write
	neg rax						; Invertion du signe de rax
	mov r8, rax					; Copie de rax dans r8
	push r8						; Sauvegarde de r8 sur la stack
	call __errno_location		; Appel de la fonction __errno_location pour connaitre l'address de l'errno, résultat dans rax
	pop r8						; Récupération de la dernière de la stack donnée dans r8
	mov [rax], r8				; Copie de r8 dans l'address pointé par rax
	mov rax, -1					; Mise à -1 de rax
	ret							; Retour de la valeur rax

.end:							; Label .end pour executer la fin de ft_write
	ret							; Retour de la valeur rax