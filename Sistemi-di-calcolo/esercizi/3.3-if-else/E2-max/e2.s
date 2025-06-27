.globl max
max:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    cmpl %ecx, %eax
    jg E
    movl %ecx, %eax
E:
    ret
