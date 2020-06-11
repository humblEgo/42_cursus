; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strdup.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/09 11:46:16 by iwoo              #+#    #+#              #
;    Updated: 2020/06/09 11:46:16 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

		section	.text
		extern	_malloc
		extern	_ft_strlen
		extern	_ft_strcpy
		global	_ft_strdup

_ft_strdup:
		push	rdi
		cmp		rdi, 0
		je		ERROR

		call	_ft_strlen
		inc		rax
		mov		rdi, rax
		call	_malloc
		cmp		rax, 0
		jbe		ERROR
		pop		rsi
		mov		rdi, rax
		call	_ft_strcpy
		ret

ERROR:
		pop		rdi
		mov		rax, 0x0
		ret
