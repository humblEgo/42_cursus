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
		push	rdi
		call	ft_strlen
		inc		rax
		mov		rdi, rax
		call	malloc
		push	rax
		cmp		rax, 0
		jbe		error
		pop		rdi
		pop		rsi
		call	ft_strcpy
		ret

error:
		mov		rax, 0x0
		ret
