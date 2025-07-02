.globl count1

count1:
    movl 4(%esp), %edx
    xorl %eax, %eax
L:
    testl %edx, %edx
    jbe E
    testl $1, %edx
    jz F
    incl %eax
F:
    shrl $1, %edx
    jmp L
E:
    ret
