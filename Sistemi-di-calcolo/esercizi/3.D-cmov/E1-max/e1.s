.globl max

max:
	movl 4(%esp), %eax
	movl 8(%esp), %edx
	cmpl %edx, %eax
	cmovlel %edx, %eax
	ret
