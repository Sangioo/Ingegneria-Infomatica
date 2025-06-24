.globl g
g:
    movl 4(%esp), %eax
    xorl %ecx, %ecx
    xorl %edx, %edx
    addl 8(%esp), %eax
    ret
