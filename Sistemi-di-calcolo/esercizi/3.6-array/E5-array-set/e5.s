.globl array_set

array_set:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    sall $1, %ecx
    addl %ecx, %eax
    subl $2, %eax
    movl 4(%esp), %ecx
    movw 12(%esp), %dx
L:
    cmpl %ecx, %eax
    jl E
    movw %dx, (%eax)
    subl $2, %eax
    jmp L
E:
    ret
