#int max(int x, int y) {
#    int a = x, c = y;
#    if (c<=a) goto E; // (c-a<=0)
#    a = c;
#E:
#    return a;
#}

.globl max
 max:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    cmpl %eax, %ecx
    jle E
    movl %ecx, %eax
E:  ret
