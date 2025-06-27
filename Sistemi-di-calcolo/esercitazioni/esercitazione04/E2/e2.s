.globl find

find:
    movl 4(%esp), %edx
    movl 8(%esp), %ecx
    movl 12(%esp), %eax

G:
    cmpl $0, %ecx
    je E
    cmpl %eax, (%edx)
    je F
    addl $4, %edx
    decl %ecx
    jmp G
E:
    xorl %eax, %eax
    ret
F:
    movl $1, %eax
    ret
