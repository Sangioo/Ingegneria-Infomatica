.globl sum
sum:
    xorl %eax, %eax     # int a = 0;
    movl 4(%esp), %ecx  # int c = n;
L:
    testl %ecx, %ecx    # if (c<=0) 
    jle E               # goto E; 
    addl %ecx, %eax     # a += c;
    decl %ecx           # c--;
    jmp L               # goto L;
E:
    ret                 # return a;