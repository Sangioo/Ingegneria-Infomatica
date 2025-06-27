.globl find_youngest

find_youngest:
    pushl %ebx
    movl 8(%esp), %edx
    xorl %eax, %eax
    xorl %ecx, %ecx
L:
    cmpl 12(%esp), %ecx
    jge E

    testl %eax, %eax
    jz F
    movb 8(%edx, %ecx), %bl
    cmpb 8(%eax), %bl
    jl F
    jmp G
F:
    leal (%edx, %ecx), %eax
G:

    addl $12, %ecx
    jmp L
E:
    popl %ebx
    ret
