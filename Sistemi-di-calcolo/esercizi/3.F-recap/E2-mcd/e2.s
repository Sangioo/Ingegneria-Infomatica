.globl mcd

mcd: # int mcd(int x, int y)
	pushl %ebx
	movl 8(%esp), %eax 			# int a = x;
	movl 12(%esp), %ecx 		# int c = y;
L:  testl %ecx, %ecx			# if (c==0) 
	je E						#	goto E;
    movl %ecx, %ebx			    # int b = c;
    movl %eax, %edx             # int d = a;
    sarl $31, %edx              # d = d >> 31;
    idivl %ecx					# d = a % c;
	movl %edx, %ecx             # c = d;
    movl %ebx, %eax             # a = b;
    jmp L						# goto L;
E:  popl %ebx
	ret 						# return a;

