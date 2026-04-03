.globl get

get:
    movl 4(%esp), %ecx
    movl 12(%esp), %edx
    cmpl 8(%esp), %edx
    jb E
    movw $-1, %ax
    jmp F
E:
    movw (%ecx, %edx, 2), %ax
F:
    ret
