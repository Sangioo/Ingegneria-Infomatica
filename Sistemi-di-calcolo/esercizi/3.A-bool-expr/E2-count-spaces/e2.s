.globl count_spaces

count_spaces:
	movl 4(%esp), %ecx
	xorl %eax, %eax
L:
	cmpb $0, (%ecx)
	je E

	cmpb $32, (%ecx)
	sete %dl
	movsbl %dl, %edx
	addl %edx, %eax
	incl %ecx

	jmp L
E:
	ret
