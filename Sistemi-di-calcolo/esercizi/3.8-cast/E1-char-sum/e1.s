.globl f

f:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
    movb (%ecx), %cl
    movb (%edx), %dl
    movsbl %cl, %ecx
    movsbl %dl, %edx
    addl %edx, %ecx
    movl %ecx, %eax
    ret
