# Scrivi la soluzione qui...

# return ebx < ecx < edx
# return x <= y && y <= z;

.globl between

between:
	pushl %ebx

	movl 8(%esp), %ebx
	movl 12(%esp), %ecx
	movl 16(%esp), %edx
	
	cmpl %ecx, %ebx
	setle %al

	cmpl %edx, %ecx
	setle %ah

	andb %ah, %al
	
	movzbl %al, %eax
	
	popl %ebx
	ret
