.globl count_matching_vars

count_matching_vars:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $8, %esp

    movl $-1, %eax
    cmpl $0, 28(%esp)
    je END
    cmpl $0, 32(%esp)
    je END
    movl 28(%esp), %ebx
    movl 32(%esp), %esi
    xorl %edi, %edi
L:
    cmpl $0, (%ebx)
    je E
    movl (%ebx), %ecx
    movl %ecx, (%esp)
    call getenv
    testl %eax, %eax
    je F
    movl %eax, (%esp)
    movl %esi, 4(%esp)
    call strstr
    testl %eax, %eax
    je F
    incl %edi
F:
    addl $4, %ebx
    jmp L
E:
    movl %edi, %eax
END:
    addl $8, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
