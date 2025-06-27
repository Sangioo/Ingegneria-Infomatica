.globl f
f:
    # prologo
    pushl %ebx      
    pushl %ebp
    subl $4, %esp
    #
    movl $1, %ebx           # int b = 1
    movl $2, %ebp           # bp = 2;
    movl 16(%esp), %ecx     # int c = x;
    incl %ecx
    movl %ecx, (%esp)
    call g                  # int a = g(c + 1);
    addl %ebx, %eax         # a = a + b;
    addl %ebp, %eax         # a = a + bp;
    # epilogo
    addl $4, %esp
    popl %ebp
    popl %ebx
    #
    ret                     # return a;