; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_list_size.s                                     :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/10 10:20:02 by iwoo              #+#    #+#              #
;    Updated: 2020/06/10 10:20:02 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;int	ft_list_size(t_list *begin_list)
;{
;	int		size;
;	t_list	*node;
;
;	size = 0;
;	node = begin_list 
;	while (node)
;	{
;		size++;
;		node = node->next;
;	}
;	return (size);
;}

		section	.text
		global	_ft_list_size

_ft_list_size:
		push	rsp
		xor		rcx, rcx
		cmp		rdi, 0
		je		END

SIZE_LOOP:
		cmp		rdi, 0
		jz		END
		inc		rcx
		mov		rdi, [rdi + 8]
		jmp		SIZE_LOOP	

END:
		pop		rsp
		mov		rax, rcx
		ret
