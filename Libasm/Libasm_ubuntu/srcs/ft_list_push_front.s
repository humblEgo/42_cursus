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
		push	rbp					;rsp -> rbp
		mov		rbp, rsp

		cmp		rdi, 0
		je		end
		push	rdi

		cmp		rsi, 0
		je		end
		push	rsi

		mov		rdi, 16
		call	malloc
		cmp		rax, 0
		jz		end
		pop		rsi					; new data ptr
		pop		rdi					; begin list ptr의 주소
		mov		[rax], rsi			; 뉴데이터를 말록된 data 주소에 넣는다.(8칸)
		mov		rcx, [rdi]			; begin list ptr을 rcx에 넣는다.
		mov		[rax + 8], rcx		; rcx에 저장된 begin list ptr을 rax로부터 8칸 떨어진 곳에 넣는다.
		mov		[rdi], rax			; *begin = new

end:
		pop		rbp
		ret
