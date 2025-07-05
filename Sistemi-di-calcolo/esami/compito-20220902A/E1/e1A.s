.globl div_vectors

div_vectors:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp

    xorl %eax, %eax
    cmpl $0, 24(%esp)
    je END
    cmpl $0, 28(%esp)
    je END
    cmpl $0, 32(%esp)
    je END
    
    movl 32(%esp), %eax
    sall $2, %eax
    movl %eax, (%esp)
    call malloc
    movl %eax, %ebx
    movl 24(%esp), %edi
    movl 28(%esp), %esi
    xorl %ecx, %ecx
L:
    cmpl 32(%esp), %ecx
    jge E
    movl (%edi, %ecx, 4), %eax
    movl (%esi, %ecx, 4), %ebp
    xorl %edx, %edx
    idivl %ebp
    movl %eax, (%ebx, %ecx, 4)
    incl %ecx
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
