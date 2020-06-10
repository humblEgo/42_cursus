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
		global	ft_write

ft_write:
		mov		rax, 1
		syscall
		cmp		rax, 0x0
		js		error
		ret

error:
		mov		rax, -0x1
		ret
