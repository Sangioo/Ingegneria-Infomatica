.globl f

f:									# int f(int x, int y){
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl %eax, %edx					# int z = x;
	addl %ecx, %edx					# z += y;
	cmpl $15, %edx					# if (z > 15) goto E;
	jg E
	movl $0, %eax					# return 0;
	ret

E:
    movl $1, %eax					# return 1;
	ret
