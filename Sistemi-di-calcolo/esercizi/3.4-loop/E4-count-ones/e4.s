.globl count1

count1:
    movl 4(%esp), %ecx
    xorl %eax, %eax
L:
    testl %ecx, %ecx
    jz E

    testl $1, %ecx
    jz F
    incl %eax
F:
    shrl $1, %ecx
    jmp L
E:
    ret
