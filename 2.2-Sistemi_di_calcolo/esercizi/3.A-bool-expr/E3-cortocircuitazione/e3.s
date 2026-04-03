.globl stringa_vuota

stringa_vuota:
    movl 4(%esp), %ecx
    xorl %eax, %eax
    testl %ecx, %ecx
    je E
    cmpb $0, (%ecx)
    jne E
    movl $1, %eax
E:
    ret
