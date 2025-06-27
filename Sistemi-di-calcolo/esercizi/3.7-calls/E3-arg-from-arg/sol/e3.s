.globl f
f:
    subl $4, %esp
    movl 8(%esp), %eax
    movl %eax, (%esp)
    call g              # int a = g(x);
    incl %eax           # a = a + 1;
    addl $4, %esp
    ret                 # return a;
