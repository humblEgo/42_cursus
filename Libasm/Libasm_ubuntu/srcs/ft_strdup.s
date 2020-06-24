; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strdup.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/08 23:46:59 by iwoo              #+#    #+#              #
;    Updated: 2020/06/08 23:46:59 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;char	*ft_strdup(const char *s)
;{
;	char	*dup;
;	int		len;
;	int		i;
;
;	len = 0;
;	while (s[len])
;		len++;
;	if (!(dup = (char *)malloc(sizeof(char) * len + 1)))
;		return (NULL);
;	i = -1;
;	while (++i < len)
;		dup[i] = s[i];
;	dup[i] = '\0';
;	return (dup);
;}

section	.text
extern	malloc
extern	ft_strlen
extern	ft_strcpy
		global	ft_strdup

ft_strdup:
;		push	rbp
;		mov		rbp, rsp
	;	push	rsp
		sub		rsp, 8
;		push	rdi
		mov		[rsp], rdi

		call	ft_strlen
		inc		rax
		mov		rdi, rax
		call	malloc
;		mov		[rsp + 8], rax
;		push	rax
		cmp		rax, 0
		jbe		error
		mov		rdi, rax
;		mov		rdi, qword [rsp + 8]
		mov		rsi, qword [rsp]
;		pop		rdi
;		pop		rsi
		call	ft_strcpy
;		pop		rbp
;		pop		rsp
		add		rsp, 8
		ret

error:
		add		rsp, 8
;		pop		rbp
		mov		rax, 0x0
		ret
