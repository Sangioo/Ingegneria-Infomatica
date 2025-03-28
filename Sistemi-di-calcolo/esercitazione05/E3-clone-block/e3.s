.globl clone

clone:
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $12, %esp

    movl 28(%esp), %edi
    movl 32(%esp), %esi

    movl %esi, (%esp)
    call malloc
    movl %eax, %ebx
    cmpl $0, %ebx
    jne E
    xorl %eax, %eax
    jmp F
E:
    movl %ebx, (%esp)
    movl %edi, 4(%esp)
    movl %esi, 8(%esp)
    call memcpy
    movl %ebx, %eax
F:
    addl $12, %esp
    popl %ebx
    popl %esi
    popl %edi
    ret
