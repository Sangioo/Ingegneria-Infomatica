.globl f

f:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    movsbl (%eax), %eax
    movsbl (%ecx), %ecx
    addl %ecx, %eax
    ret
