.globl f

f:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl %eax, %edx
	sarl $31, %edx
	idivl %ecx
	ret
