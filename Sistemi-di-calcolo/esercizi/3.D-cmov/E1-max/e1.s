.globl max

max: # int max(int x, int y)
	movl 4(%esp), %eax            # int a = x;
	movl 8(%esp), %ecx            # int c = y;
	cmpl %eax, %ecx
	cmovgl %ecx, %eax             #	if (c<=a) goto E;
	                              # a=c;
	ret                           # return a;

