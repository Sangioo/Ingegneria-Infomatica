.globl comp

comp:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
    movl (%ecx), %eax
    subl (%edx), %eax
    ret
