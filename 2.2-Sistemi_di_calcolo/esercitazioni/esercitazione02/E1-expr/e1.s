.globl f

f:
    movl $2, %eax
    addl $3, %eax

    movl $4, %ecx
    subl $2, %ecx

    movl $2, %edx
    addl $3, %edx

    imull %ecx, %eax
    subl %edx, %eax
    imull $3, %eax

    addl $1, %eax
    ret
