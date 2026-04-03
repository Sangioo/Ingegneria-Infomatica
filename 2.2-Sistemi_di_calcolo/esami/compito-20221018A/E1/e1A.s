.globl str_to_upper

str_to_upper:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp

    xorl %eax, %eax
    cmpl $0, 24(%esp)
    je END

    movl 24(%esp), %ecx
    movl %ecx, (%esp)
    call strdup
    movl %eax, %ebx
    movl %eax, %edi
L:
    cmpb $0, (%ebx)
    je E
    movb (%ebx), %cl
    movsbl %cl, %ecx
    movl %ecx, (%esp)
    call toupper
    movb %al, (%ebx)
    incl %ebx
    jmp L
E:
    movl %edi, %eax
END:
    addl $4, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
