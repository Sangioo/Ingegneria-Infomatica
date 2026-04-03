.globl f

f:
	pushl %ebx
	pushl %edi
	pushl %esi
	subl $4, %esp
	movl 20(%esp), %ebx
	xorl %edi, %edi
	xorl %esi, %esi
L:
	cmpl 24(%esp), %edi
	jae E

	movl (%ebx, %edi, 4), %ecx
	movl %ecx, (%esp)
	call is_negative
	addl %eax, %esi

	incl %edi
	jmp L
E:
	movl %esi, %eax
	addl $4, %esp
	popl %esi
	popl %edi
	popl %ebx
	ret
