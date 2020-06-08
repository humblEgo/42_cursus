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
		global	ft_strcpy

ft_strcpy:
		push	rbp
		mov		rbp, rsp

		xor		al, al
		xor		rcx, rcx

strcpy_loop:
		cmp		byte [rsi + rcx], 0
		je		set_null_terminator
		mov		al, byte [rsi + rcx]
		mov		byte [rdi + rcx], al
		inc		rcx
		jne		strcpy_loop

set_null_terminator:
		mov		BYTE [rdi + rcx], 0

end:
		mov		rax, rdi
		pop		rbp
		ret
