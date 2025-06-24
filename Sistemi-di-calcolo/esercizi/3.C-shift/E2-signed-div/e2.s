.globl f

f:                       # int f(int x, int y)
	movl 4(%esp), %eax   # int a = x;
	movl 8(%esp), %ecx   # int c = y;
	movl %eax, %edx      # int d = a;
	sarl $31, %edx       # d = d >> 31;
	idivl %ecx           # a = a / c;
    ret                  # return a;

