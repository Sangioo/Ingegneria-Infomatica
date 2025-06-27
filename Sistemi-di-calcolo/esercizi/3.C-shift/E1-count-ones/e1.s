# Scrivere soluzione qui...

.globl count1

count1: # unsigned count1(unsigned n) {
	movl 4(%esp), %ecx         # unsigned c = n;
    movl $0, %eax              # unsigned a = 0; // counter
L:  testl %ecx, %ecx           # if (c==0) 
	je E                       #	goto E;
    testl $1, %ecx             # if ((c & 1) == 0) 
	je A                       #	goto A;
    incl %eax                  # a++;
A:  shrl %ecx                  # c = c >> 1;
    jmp L                      # goto L;
E:  ret                        # return a;

