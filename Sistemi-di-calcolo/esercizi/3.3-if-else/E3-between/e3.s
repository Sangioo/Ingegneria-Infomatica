.globl between
between:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    movl 12(%esp), %edx
    cmpl %ecx, %eax
    jg E
    cmpl %edx, %ecx
    jg E
    movl $1, %eax
    jmp F
E:
    xorl %eax, %eax
F:
    ret
