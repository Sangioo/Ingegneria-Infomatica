.globl strings_are_upper

strings_are_upper:
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
    movl %eax, %ebx     # res
    xorl %edi, %edi     # i
    movl 24(%esp), %esi # array
L:
    cmpl 28(%esp), %edi
    jge E

    movl (%esi, %edi, 4), %ebp      # s
    movl $1, (%ebx, %edi, 4)
L1:
    cmpb $0, (%ebp)
    je E1
    movb (%ebp), %cl
    movb %cl, (%esp)
    call isupper
    test %eax, %eax
    jne FI
    movl $0, (%ebx, %edi, 4)
    jmp E1
FI:
    incl %ebp
    jmp L1
E1:

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
