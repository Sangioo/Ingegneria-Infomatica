.globl between

between:
	movw 4(%esp), %cx
	movw 8(%esp), %dx
	cmpw %dx, %cx
	setle %al
	movw 12(%esp), %cx
	cmpw %cx, %dx
	setle %ah
	andb %ah, %al
	movsbl %al, %eax
	ret
