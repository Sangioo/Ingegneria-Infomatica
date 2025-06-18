.globl adler32

adler32:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $8, %esp

    movl 28(%esp), %ebx
    xorl %eax, %eax

    testl %ebx, %ebx
    jz END
    cmpl $0, 32(%esp)
    jz END

    leal 4(%esp), %edx
    movl %edx, (%esp)
    call get_adler_constant
    movl 4(%esp), %ebp

    movl $1, %esi
    xorl %edi, %edi
    xorl %ecx, %ecx
L:
    cmpl 32(%esp), %ecx
    jge E

    movl %esi, %eax
    addl (%ebx, %ecx, 1), %eax
    xorl %edx, %edx
    idivl %ebp
    movl %edx, %esi

    movl %esi, %eax
    addl %edi, %eax
    xorl %edx, %edx
    idivl %ebp
    movl %edx, %edi

    incl %ecx
    jmp L
E:
    movl %edi, %eax
    shll $16, %eax
    orl %esi, %eax
END:
    addl $8, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
