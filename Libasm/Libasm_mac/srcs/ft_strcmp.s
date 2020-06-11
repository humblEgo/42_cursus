; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strcmp.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/08 20:34:35 by iwoo              #+#    #+#              #
;    Updated: 2020/06/08 20:34:35 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;int	ft_strcmp(const char *s1, const char *s2)
;{
;	int i;
;
;	i = 0;
;	while (s1[i] && s2[i] && (s1[i] == s2[i]))
;		i++;
;	return (s1[i] - s2[i]);
;}

section	.text
		global	_ft_strcmp

_ft_strcmp:
		push	rbp
		mov		rbp, rsp

		xor		rax, rax
		xor		rcx, rcx

STRCMP_LOOP:
		cmp		BYTE [rdi + rcx], 0
		je		END
		cmp		BYTE [rsi + rcx], 0
		je		END
		mov		al, BYTE [rdi + rcx]
		cmp		BYTE [rsi + rcx], al
		jne		END
		inc		rcx
		jmp		STRCMP_LOOP

END:
		mov		al, BYTE [rdi + rcx]
		sub		al, BYTE [rsi + rcx]
		movsx	rax, al
		leave
		ret
