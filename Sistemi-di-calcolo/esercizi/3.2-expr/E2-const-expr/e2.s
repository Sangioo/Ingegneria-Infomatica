.globl f
f:
    movl $3, %eax    #    int a = 3;
    imull $4, %eax   #    a = a * 4;
    movl $2, %ecx    #    int c = 2;
    imull $5, %ecx   #    c = c * 5;
    addl %ecx, %eax  #    a = a + c;
    decl %eax        #    a = a - 1;
    ret              #    return a;
