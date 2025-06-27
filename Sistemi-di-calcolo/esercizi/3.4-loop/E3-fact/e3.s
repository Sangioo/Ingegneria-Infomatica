.globl fact
fact:
    movl 4(%esp), %edx
    movl $1, %eax
    movl $2, %ecx
L:
    cmpl %edx, %ecx
    ja E

    imull %ecx, %eax

    incl %ecx
    jmp L
E:
    ret
