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
		global	ft_list_size

ft_list_size:
		push	rbp
		mov		rbp, rsp

		xor		rcx, rcx
size_loop:
		cmp		rdi, 0
		jz		end
		inc		rcx
		mov		rdi, [rdi + 8]
		jmp		size_loop

end:
		pop		rbp
		mov		rax, rcx
		ret
