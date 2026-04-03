.globl lcm

lcm:
    pushl %esi
    pushl %edi
    movl 12(%esp), %esi
    movl 16(%esp), %edi
    movl %edi, %ecx
    cmpl %edi, %esi
    cmovg %esi, %ecx
E:
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl %esi
    testl %edx, %edx
    jnz F
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl %edi
    testl %edx, %edx
    jnz F
    movl %ecx, %eax
    popl %edi
    popl %esi
    ret
F:
    incl %ecx
    jmp E
