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
;	t_list	tmp;
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
;			if (cmp(p->data, remember.data) > 0)
;			{
;				tmp.data = p->next->data;
;				p->next->data = p->data;
;				p->data = remember.data;
;			}
;			p = p->next;
;		}
;		i++;
;	}
;}
		section .text
		extern	_ft_list_size
		global	_ft_list_sort

_ft_list_sort:
		push	rsp

		cmp		rdi, 0						; if (begin_list == NULL)
		je		END						; return 
		mov		rax, [rdi]					
		cmp		rax, 0						; if (*begin_list == NULL)
		je		END							; return
		mov		r14, rdi					; r14 = begin_list
		cmp		rsi, 0						; if (cmp == NULL)
		je		END							; return
		mov		r9, rsi						; r9 = cmp

		mov		rdi, [rdi]					; param = *begin_list 
		call	_ft_list_size				; ft_list_size(param)
		mov		r10, rax					; r10 = list_size
		xor		rcx, rcx					; rcx = 0

SORT_LOOP:
		cmp		rcx, r10					; if (i < size)
		je		END							; return
		mov		r11, [r14]					; r11 = (*begin_list);
		jmp		SORT_ACTION_LOOP

INCREASE_COUNT:
		inc		rcx							; rcx++
		jmp		SORT_LOOP					

SORT_ACTION_LOOP:
		mov		rbx, [r11 + 8]				; rbx = r11->next;
		cmp		rbx, 0						; if (r11->next == NULL)
		je		INCREASE_COUNT				; end sort_acton_loop
		mov		rdi, qword [r11]			; rdi = r11->data;
		mov		rsi, qword [rbx]			; rsi = r11->next->data;
		push	rcx							; save rcx
		call	r9							; call cmp function
		pop		rcx							; load rcx
		cmp		rax, 0						; if (cmp(p->data, p->next->data) > 0)
		jg		SWAP_DATA					

MOVE_TO_NEXT_LINK:
		mov		r11, [r11 + 8]				; r11 = r11->next
		jmp		SORT_ACTION_LOOP

SWAP_DATA:
		mov		rax, rsi					; tmp.data = r11->next->data
		mov		[rbx], rdi					; r11->next->data = r11->data
		mov		[r11], rax					; r11->data = r11->next->data
		jmp		MOVE_TO_NEXT_LINK			
		
END:
		pop		rsp
		ret
