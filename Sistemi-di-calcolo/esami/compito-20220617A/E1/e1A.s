.globl crc32

crc32:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp

    movl 20(%esp), %ebp
    movl $0xFFFFFFFF, %eax
    xorl %edi, %edi
L1:
    cmpl 24(%esp), %edi
    jge E1
    movsbl (%ebp, %edi), %ecx
    xorl %ecx, %eax
    xorl %esi, %esi
L2:
    cmpl $8, %esi
    jge E2
    movl %eax, %edx
    andl $1, %edx
    negl %edx
    movl %eax, %ebx
    sarl $1, %ebx
    andl $0xEDB88320, %edx
    xorl %ebx, %edx
    movl %edx, %eax
    incl %esi
    jmp L2
E2:
    incl %edi
    jmp L1
E1:
    notl %eax
    
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
