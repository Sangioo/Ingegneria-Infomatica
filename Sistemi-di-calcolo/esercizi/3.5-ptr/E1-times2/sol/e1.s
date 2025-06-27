.globl times2

times2:
    movl 4(%esp), %ecx
    movw (%ecx), %ax
    addw %ax, (%ecx)
    ret
