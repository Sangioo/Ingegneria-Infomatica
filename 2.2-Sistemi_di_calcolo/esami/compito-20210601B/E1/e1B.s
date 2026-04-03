.globl adler32_simplified

adler32_simplified:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp

    movl 20(%esp), %edi
    movl 24(%esp), %esi
    movl $1, %eax
    xorl %ebx, %ebx
    xorl %ecx, %ecx
L:
    cmpl %esi, %ecx
    jge E
    movl %eax, %edx
    movzbl (%edi, %ecx), %ebp
    addl %ebp, %edx
    andl $0xFFFF, %edx
    movl %edx, %eax
    movl %ebx, %edx
    addl %eax, %edx
    andl $0xFFFF, %edx
    movl %edx, %ebx
    incl %ecx
    jmp L
E:
    shll $16, %ebx
    orl %ebx, %eax

    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
