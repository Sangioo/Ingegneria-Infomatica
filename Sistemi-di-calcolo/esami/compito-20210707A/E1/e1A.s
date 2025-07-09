.globl suffix

suffix:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp

    movl 24(%esp), %ebp
    movl %ebp, (%esp)
    call strlen
    movl %eax, %edi

    movl 28(%esp), %ebx
    movl %ebx, (%esp)
    call strlen
    movl %eax, %esi

    xorl %eax, %eax
    cmpl %edi, %esi
    jg END
    movl %edi, %ecx
    subl %esi, %ecx
L:
    cmpl %edi, %ecx
    jge E
    movb (%ebp, %ecx), %dl
    movb (%ebx), %dh
    cmpb %dh, %dl
    jne END
    incl %ebx
    incl %ecx
    jmp L
E:
    movl $1, %eax
END:
    addl $4, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
