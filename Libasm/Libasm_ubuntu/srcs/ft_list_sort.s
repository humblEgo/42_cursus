; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_list_sort.s                                     :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2020/06/10 15:18:31 by iwoo              #+#    #+#              #
;    Updated: 2020/06/10 15:18:31 by iwoo             ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;void	ft_list_sort_piscine(t_list **begin_list, int (*cmp)())
;{
;	t_list	*p;
;	t_list	remember;
;	int		size;
;	int		i;
;	
;	if (!begin_list || !(*begin_list) || !cmp)
;		return ;
;	size = ft_list_size(*begin_list);
;	i = 0;
;	while (i < size)
;	{
;		p = *begin_list;
;		while (p->next != NULL)
;		{
;			remember.data = p->next->data;
;			if (cmp(p->data, remember.data) > 0)
;			{
;				p->next->data = p->data;
;				p->data = remember.data;
;			}
;			p = p->next;
;		}
;		i++;
;	}
;}

		section .text
		extern	ft_list_size
		global	ft_list_sort

ft_list_sort:
		;push	rbp
		;mov		rbp, rsp

		cmp		rdi, 0						; if (begin_list == NULL)
		je		end							; return 
		mov		rax, [rdi]					
		cmp		rax, 0						; if (*begin_list == NULL)
		je		end							; return
		mov		r14, rdi					; r14 = begin_list
		cmp		rsi, 0						; if (cmp == NULL)
		je		end							; return
		mov		r9, rsi						; r9 = cmp

		mov		rdi, [rdi]					; param = *begin_list 
		call	ft_list_size				; ft_list_size(param)
		mov		r10, rax					; r10 = list_size
		xor		rcx, rcx					; rcx = 0

sort_loop:
		cmp		rcx, r10					; if (i < size)
		je		end							; return
		mov		r11, [r14]					; r11 = (*begin_list);
		jmp		sort_action_loop

increase_count:
		inc		rcx							; rcx++
		jmp		sort_loop					

sort_action_loop:
		mov		rbx, [r11 + 8]				; rbx = r11->next;
		cmp		rbx, 0						; if (r11->next == NULL)
		je		increase_count				; end sort_acton_loop
		mov		rdi, qword [r11]			; rdi = r11->data;
		mov		rsi, qword [rbx]			; rsi = r11->next->data;
		push	rcx							; save rcx
		call	r9							; call cmp function
		pop		rcx							; load rcx
		cmp		rax, 0						; if (cmp(p->data, p->next->data) > 0)
		jg		swap_data					

move_to_next_link:
		mov		r11, [r11 + 8]				; r11 = r11->next
		jmp		sort_action_loop

swap_data:
		mov		rax, rsi					; remember.data = r11->next->data
		mov		[rbx], rdi					; r11->next->data = r11->data
		mov		[r11], rax					; r11->data = r11->next->data
		jmp		move_to_next_link			
		
end:
		;pop		rbp
		ret
