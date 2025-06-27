.globl fill

fill:
    movl 4(%esp), %eax

    movb 8(%esp), %cl
    movb %cl, (%eax)

    movl 12(%esp), %ecx
    movl %ecx, 4(%eax)

    movb 16(%esp), %cl
    movb %cl, 8(%eax)

    ret
