.globl crc32b

crc32b:
    pushl %esi
    pushl %edi
    pushl %ebx
    pushl %ebp

    movl 24(%esp), %ecx
    xorl %ebx, %ebx
    notl %ebx
    movl %ebx, %eax
E:
    cmpl $0, %ecx
    jle F

    jmp E
F:
    popl %ebp
    popl %ebx
    popl %edi
    popl %esi
    ret