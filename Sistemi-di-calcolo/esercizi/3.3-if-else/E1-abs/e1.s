.globl myabs
myabs:
	movl 4(%esp), %eax	# int a = x;
    cmpl $0, %eax		# if (a>=0) 
	jge L				# goto L;
	negl %eax			# a = -a;
L:
    ret 				# return a;
