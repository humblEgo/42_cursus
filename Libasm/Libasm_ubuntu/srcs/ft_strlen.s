section .text
		global ft_strlen

ft_strlen:
		push rbp
		mov rbp, rsp				; setup the stack frame

		xor rax, rax				; init rax as 0

strlen_loop:
		cmp byte [rdi + rax], 0x0	; 매개변수로 들어온 rdi를 byte단위로 읽어서 null과 비교!
		je end
		inc rax
		jne strlen_loop				; jne는 conditional jum. Jump not equal or jump not zero
		
end:
		pop rbp
		ret
