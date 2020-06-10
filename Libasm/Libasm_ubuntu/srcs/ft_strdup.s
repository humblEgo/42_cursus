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
		global	ft_strdup

ft_strdup:
		mov		rax, rax
