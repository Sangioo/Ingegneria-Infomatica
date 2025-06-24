.globl f

f:
    movl 4(%esp), %eax
    incl %eax
    ret

