.globl crc32b

crc32b:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $12, %esp

    movl 32(%esp), %edi
    movl 36(%esp), %esi
    xorl %ebx, %ebx
    notl %ebx
    movl %ebx, %ebp
L:
    testl %esi, %esi
    je E
    decl %esi
    movsbl (%edi), %ecx
    incl %edi
    movl %ebp, %edx
    xorl %ecx, %edx
    leal 8(%esp), %eax
    movl %eax, (%esp)
    andl $0xFF, %edx
    movl %edx, 4(%esp)
    call get_constant
    movl %ebp, %eax
    sarl $8, %eax
    movl 8(%esp), %ecx
    xorl %ecx, %eax
    movl %eax, %ebp
    jmp L
E:
    movl %ebp, %eax
    xorl %ebx, %eax

    addl $12, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
