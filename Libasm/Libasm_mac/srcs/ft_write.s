; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_write.s                                         :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/08 20:14:46 by iwoo              #+#    #+#              #
;    Updated: 2020/06/08 20:14:46 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section	.text
extern	___error
		global	_ft_write

_ft_write:
		mov		rax, 0x2000004
		syscall
		jc		error
		ret

error:
		push	rax
		call	___error
		pop		qword [rax]
		mov		rax, -0x1
		ret
