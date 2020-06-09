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
extern	___error
		global	_ft_strdup

_ft_strdup:
		push	rdi
		call	_ft_strlen
		inc		rax
		mov		rdi, rax
		call	_malloc
		push	rax
		cmp		rax, 0
		jbe		error
		pop		rdi
		pop		rsi
		call	_ft_strcpy
		ret

error:
		push	rax
		call	___error
		pop		qword [rax]
		mov		rax, 0x0
		ret
