.globl f

f:
    subl $24, %esp
    movl 28(%esp), %ecx
    movl 32(%esp), %edx
    leal 16(%esp), %eax
    movl %eax, (%esp)
    leal 20(%esp), %eax
    movl %eax, 4(%esp)
    movl %ecx, 8(%esp)
    movl %edx, 12(%esp)
    call get_div_rem
    movl 16(%esp), %eax
    addl $24, %esp
    ret
