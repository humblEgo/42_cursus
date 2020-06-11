; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_read.s                                          :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/08 20:32:06 by iwoo              #+#    #+#              #
;    Updated: 2020/06/08 20:32:06 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

		section	.text
		extern	___error
		global	_ft_read	

_ft_read:
		mov		rax, 0x2000003
		syscall
		jc		ERROR
		ret

ERROR:
		push	rax
		call	___error
		pop		qword [rax]
		mov		rax, -0x1
		ret
