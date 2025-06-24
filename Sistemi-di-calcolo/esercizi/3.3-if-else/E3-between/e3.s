.globl between
between:
    movl 4(%esp), %eax  # int a = x;
    movl 8(%esp), %ecx  # int c = y;
    movl 12(%esp), %edx # int d = z;
    cmpl %ecx, %eax     # if (a > c) 
    jg F                # goto F;
    cmpl %edx, %ecx     # if (c > d) 
    jg F2               # goto F2;
    movl $1, %eax       # a = 1;
    ret                 # goto E;
F:
F2:
    xorl %eax,%eax      # a = 0;
    ret                 # return a;

