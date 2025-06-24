.globl f
f:
    movw 4(%esp), %ax
    xorw %cx, %cx
    movw 8(%esp), %dx
    movw $0, %dx
    movw 12(%esp), %dx
    movw $0, %dx
L:  cmpw %cx, %ax
    jg E
    testw $1, %cx
    jne F
    movw 8(%esp), %dx
    addw %cx, %dx
    jmp C
F:
    movw 12(%esp), %dx
    addw %cx, %dx
C:
    incw %cx
E:
