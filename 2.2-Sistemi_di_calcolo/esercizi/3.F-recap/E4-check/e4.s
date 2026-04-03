.globl check

check:
    pushl %edi
    pushl %esi
    subl $16, %esp
    movl 28(%esp), %edi
    addl 36(%esp), %edi
    addl 36(%esp), %edi
    subl $2, %edi
    movl 32(%esp), %esi
L:
    cmpl 28(%esp), %edi
    jb E

    movw (%edi), %ax
    movw %ax, (%esp)
    movb (%esi), %al
    movb %al, 4(%esp)
    leal 12(%esp), %eax
    movl %eax, 8(%esp)
    call prod
    subl $2, %edi
    incl %esi
    cmpl $6, 12(%esp)
    jne F
    movl $1, %eax
    jmp G
F:

    jmp L
E:
    xorl %eax, %eax
G:
    addl $16, %esp
    popl %esi
    popl %edi
    ret
