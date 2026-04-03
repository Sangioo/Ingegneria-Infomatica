.globl strextstrd

strextstrd:
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $4, %esp

    movl 20(%esp), %esi
    movl 24(%esp), %ecx
    movl %esi, (%esp)
    call strlen
    movl %eax, %edi
    movl %eax, %edx
    sarl $31, %edx
    idivl %ecx
    incl %eax
    movl %eax, (%esp)
    call malloc
    movl %eax, %ebx
    testl %eax, %eax
    jz F
    xorl %ecx, %ecx
L:
    cmpl %edi, %ecx
    jge E
    movb (%esi, %ecx), %dl
    movb %dl, (%eax)
    incl %eax
    addl 24(%esp), %ecx
    jmp L
E:
    movb $0, (%eax)
    movl %ebx, %eax
F:

    addl $4, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret
