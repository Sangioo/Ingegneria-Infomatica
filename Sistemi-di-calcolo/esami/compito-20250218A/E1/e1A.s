.globl count_tokens
count_tokens:
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $8, %esp

    movl 24(%esp), %edi
    movl 28(%esp), %esi
    xorl %ebx, %ebx
    movl %edi, (%esp)
    movl %esi, 4(%esp)
    call strtok
L:
    testl %eax, %eax
    jz E
    incl %ebx
    movl $0, (%esp)
    movl %esi, 4(%esp)
    call strtok
    jmp L
E:
    movl %ebx, %eax

    addl $8, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret