section .text
		global	_start

_start
		xor		rax, rax	; 똑같은 값을 xor 하게 되면 반드시 0이 나온다. 물론 mov rax, 0 해도 초기화 가능하겠지
		mov		rbx, rax
		mov		rcx, rax
		mov		rdx, rax

		sub		rsp, 64		; RBP는 RSP와 동일. 64만큼의 공간을 확보
		mov		rdi, 0
		mov		rsi, rsp
		mov		rdx, 63
		syscall

		mov		rax, 1
		mov		rdi, 1
		mov		rsi, rsp
		mov		rdx, 63
		syscall

		mov		rax, 60
		syscall
