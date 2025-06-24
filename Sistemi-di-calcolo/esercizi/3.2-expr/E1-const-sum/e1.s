.globl f

f:
    #    int a;
    movl $5, %eax   #    a = 5;
    addl $7, %eax   #    a = a + 7;
    ret             #    return a;
