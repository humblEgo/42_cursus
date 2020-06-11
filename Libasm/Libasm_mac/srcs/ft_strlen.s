; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strlen.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/09 07:59:30 by iwoo              #+#    #+#              #
;    Updated: 2020/06/09 07:59:31 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

		section .text
		global _ft_strlen

_ft_strlen:
		push rbp
		mov rbp, rsp				

		xor rax, rax			

STRLEN_LOOP:
		cmp byte [rdi + rax], 0x0
		je END
		inc rax
		jne STRLEN_LOOP	
		
END:
		leave
		ret
