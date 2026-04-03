.globl count_vars

count_vars:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp

    xorl %eax, %eax
    cmpl $0, 24(%esp)
    je END
    cmpl $0, 28(%esp)
    jle END
    movl 28(%esp), %eax
    sall $2, %eax
    movl %eax, (%esp)
    call malloc
    movl %eax, %ebx
    xorl %edi, %edi
    movl 24(%esp), %esi
L:
    cmpl 28(%esp), %edi
    jge E
    movl (%esi, %edi, 4), %ecx
    movl %ecx, (%esp)
    call getenv
    testl %eax, %eax
    je F
    movl $1, (%ebx, %edi, 4)
    jmp G
F:
    movl $0, (%ebx, %edi, 4)
G:
    incl %edi
    jmp L
E:
    movl %ebx, %eax
END:
    addl $4, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
