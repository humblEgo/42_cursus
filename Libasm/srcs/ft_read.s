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
		global	ft_read	

ft_read:
		mov		rax, 0
		syscall
		cmp		rax, 0x0
		jb		error
		ret

error:
		mov		rax, -0x1
		ret
