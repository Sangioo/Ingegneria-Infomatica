.globl sum
sum:
    movl 4(%esp), %ecx
    xorl %eax, %eax
L:
    cmpl $0, %ecx
    jle E
    addl %ecx, %eax
    decl %ecx
    jmp L
E:
    ret
