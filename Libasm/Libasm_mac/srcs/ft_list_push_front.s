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
		sub		rsp, 16		

		cmp		rdi, 0
		je		END
		cmp		rsi, 0
		je		END

		mov		[rsp], rdi
		mov		[rsp + 8], rsi


		mov		rdi, 16
		call	_malloc
		cmp		rax, 0
		jz		END

		mov		rdi, qword [rsp]
		mov		rsi, qword [rsp + 8]
		mov		[rax], rsi
		mov		rcx, [rdi]
		mov		[rax + 8], rcx
		mov		[rdi], rax

END:
		add		rsp, 16
		ret
