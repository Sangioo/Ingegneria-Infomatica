.globl binsearch

binsearch:
    pushl %esi
    pushl %edi
    pushl %ebx
    movl 16(%esp), %esi
    movl 20(%esp), %edi
    movl 24(%esp), %edx
    xorl %ecx, %ecx
    xorl %eax, %eax
E:
    cmpl %edi, %ecx
    jge F
    movl %edi, %ebx
    addl %ecx, %ebx
    sarl $1, %ebx
    cmpl %edx, (%esi, %ebx, 4)
    je G
    cmpl %edx, (%esi, %ebx, 4)
    jle H
    movl %ebx, %edi
    jmp E
H:
    movl %ebx, %ecx
    incl %ecx
    jmp E
G:
    incl %eax
F:
    popl %ebx
    popl %edi
    popl %esi
    ret
