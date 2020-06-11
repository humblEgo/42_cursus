; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strcpy.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/08 18:09:10 by iwoo              #+#    #+#              #
;    Updated: 2020/06/08 18:09:10 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;char	*ft_strcpy(char *dest, const char *src)
;{
;	int	i;
;
;	i = 0;
;	while (src[i])
;	{
;		dest[i] = src[i];
;		i++;
;	}
;	return (dest);
;}

		section .text
		global	_ft_strcpy

_ft_strcpy:
		push	rbp
		mov		rbp, rsp

		xor		al, al
		xor		rcx, rcx

STRCPY_LOOP:
		cmp		byte [rsi + rcx], 0
		je		SET_NULL_TERMINATOR
		mov		al, byte [rsi + rcx]
		mov		byte [rdi + rcx], al
		inc		rcx
		jne		STRCPY_LOOP

SET_NULL_TERMINATOR:
		mov		BYTE [rdi + rcx], 0

END:
		mov		rax, rdi
		leave
		ret
