.globl swap

swap:
    movl 4(%esp), %ecx
    movw (%ecx), %ax
    movl 8(%esp), %ecx
    movw (%ecx), %dx
    movw %ax, (%ecx)
    movl 4(%esp), %ecx
    movw %dx, (%ecx)
    ret
