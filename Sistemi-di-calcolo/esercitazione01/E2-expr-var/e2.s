.globl f

f:
    movl 4(%esp), %eax
    movl %eax, %ecx

    imull %eax, %eax
    imull $2, %eax

    imull $7, %ecx
    subl %ecx, %eax
    addl $1, %eax

    ret
