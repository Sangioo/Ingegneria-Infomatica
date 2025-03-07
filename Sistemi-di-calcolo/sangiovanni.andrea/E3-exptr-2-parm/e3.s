.globl f

f:
    movl 4(%esp), %eax
    movl 4(%esp), %ecx
    movl 8(%esp), %edx

    addl %edx, %eax
    subl %edx, %ecx

    imull %ecx, %eax

    ret
