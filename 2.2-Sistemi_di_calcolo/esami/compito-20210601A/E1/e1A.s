.globl count_tokens

count_tokens:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $8, %esp

    xorl %ebx, %ebx
    movl 28(%esp), %edi
    movl %edi, (%esp)
    movl 32(%esp), %esi
    movl %esi, 4(%esp)
    call strtok
    movl %eax, %ebp
L:
    testl %ebp, %ebp
    jz E
    incl %ebx
    movl $0, (%esp)
    movl %esi, 4(%esp)
    call strtok
    movl %eax, %ebp
    jmp L
E:
    movl %ebx, %eax

    addl $8, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
