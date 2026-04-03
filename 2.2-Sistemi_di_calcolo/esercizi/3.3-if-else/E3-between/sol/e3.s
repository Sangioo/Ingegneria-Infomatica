.globl between

between:
    movl 4(%esp), %eax  # int a = x,
    movl 8(%esp), %ecx  # c = y,
    movl 12(%esp), %edx # d = z;
    cmpl %ecx, %eax     # if (a>c)
    jg E                # goto E;
    cmpl %edx, %ecx     # if (c>d)
    jg E                # goto E;
    movl $1, %eax       # a = 1;
    ret                 # return a;
E:  xorl %eax, %eax     # a = 0;
    ret                 # return a;


