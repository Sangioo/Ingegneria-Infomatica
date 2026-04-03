.globl f
f:
    movl 8(%esp), %eax
    movl 12(%esp), %edx
    movw $0, (%eax)
    movw $0, (%edx)
    xorw %cx, %cx
L:
    cmpw 4(%esp), %cx
    jg E

    testw $1, %cx
    jnz ELSE
    addw %cx, (%eax)
    jmp FI
ELSE:
    addw %cx, (%edx)
FI:

    incw %cx
    jmp L
E:
    ret
