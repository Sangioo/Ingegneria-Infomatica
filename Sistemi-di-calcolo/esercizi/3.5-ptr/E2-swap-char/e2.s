.globl swap
swap:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
    movb (%ecx), %al
    movb (%edx), %ah
    movb %ah, (%ecx)
    movb %al, (%edx)
    ret
