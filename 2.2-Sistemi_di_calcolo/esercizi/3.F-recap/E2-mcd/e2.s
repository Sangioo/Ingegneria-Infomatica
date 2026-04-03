.globl mcd

mcd:
    pushl %edi
    pushl %esi

    movl 12(%esp), %edi
    movl 16(%esp), %ecx
L:
    testl %ecx, %ecx
    je E
    movl %ecx, %esi
    movl %edi, %eax
    movl %eax, %edx
    sarl $31, %edx
    idiv %ecx
    movl %edx, %ecx
    movl %esi, %edi
    jmp L
E:
    movl %edi, %eax

    popl %esi
    popl %edi
    ret
