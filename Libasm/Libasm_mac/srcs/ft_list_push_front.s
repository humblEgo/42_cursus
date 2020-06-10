; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_list_push_front.s                               :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/09 15:01:43 by iwoo              #+#    #+#              #
;    Updated: 2020/06/09 15:01:43 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;void	ft_list_push_front(t_list **begin_list, void *data)
;{
;	t_list	*new_node;
;
;	if (begin_list != NULL && data != NULL)
;	{
;		new_node = (t_list *)malloc(sizeof(t_list) * 1);
;		if (!new_node)
;			return ;
;		new_node->next = *begin_list;
;		new_node->data = data;
;	}
;}

section	.text
extern	_malloc
		global	_ft_list_push_front

_ft_list_push_front:
		push	rbp	
		mov		rbp, rsp

		cmp		rdi, 0
		je		end
		push	rdi

		cmp		rsi, 0
		je		end
		push	rsi

		mov		rdi, 16
		call	_malloc
		cmp		rax, 0
		jz		end
		pop		rsi
		pop		rdi
		mov		[rax], rsi
		mov		rcx, [rdi]
		mov		[rax + 8], rcx
		mov		[rdi], rax

end:
		pop		rbp
		ret
