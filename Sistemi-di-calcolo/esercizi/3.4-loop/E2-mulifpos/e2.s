.globl sumwhilepos

sumwhilepos:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
    xorl %eax, %eax
L:
    testl %ecx, %ecx
    jle E
    testl %edx, %edx
    jle F
    addl %ecx, %eax
    decl %edx
F:
    decl %ecx
    jmp L
E:
    ret
