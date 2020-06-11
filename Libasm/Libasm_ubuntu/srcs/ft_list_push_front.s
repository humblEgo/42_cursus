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
		extern	malloc
		global	ft_list_push_front

ft_list_push_front:
		push	rbp
		mov		rbp, rsp

		cmp		rdi, 0				; if begin_list != NULL --> jump to end
		je		end
		push	rdi

		cmp		rsi, 0				; if data == NULL --> jump to end
		je		end
		push	rsi

		mov		rdi, 16				; allocate memory of new_node (sizeof(t_list) is 16)
		call	malloc
		cmp		rax, 0				; if malloc failed --> jump to end
		jz		end
		pop		rsi
		pop		rdi
		mov		[rax], rsi			; insert address of data to new_node->data
		mov		rcx, [rdi]
		mov		[rax + 8], rcx		; insert address of begin_list ptr to new_node->next
		mov		[rdi], rax			; insert address of new_node address to begin_list ptr address

end:
		pop		rbp
		ret
