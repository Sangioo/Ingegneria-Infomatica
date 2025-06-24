.globl f
f:
    subl $8, %esp
    movl $2, (%esp)
    movl $5, 4(%esp)
    call g              # int a = g(2, 5);
    incl %eax           # a = a + 1;
    addl $8, %esp
    ret                 # return a;
