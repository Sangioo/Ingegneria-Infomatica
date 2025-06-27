.globl mcd

mcd: # int mcd(int X, int Y) {
    pushl %ebx                      # prologo
    movl 8(%esp), %eax              # int a = X;
    movl 12(%esp), %ecx             # int c = Y;
L:  testl %ecx, %ecx                # if (c==0)
    je E                            #   goto E;
    movl %ecx, %ebx                 # int b = c;
    movl %eax, %edx
    sarl $31, %edx
    idivl %ecx                      # d = a % c;
    movl %edx, %ecx                 # c = d;
    movl %ebx, %eax                 # a = b;
    jmp L                           # goto L;
E:  popl %ebx                       # epilogo
    ret                             # return a;

