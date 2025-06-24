.globl list_add_first

list_add_first:
    pushl %esi
    pushl %ebx
    subl $4, %esp

    movl 16(%esp), %esi
    movl (%esi), %ebx
    movl $8, (%esp)
    call malloc
    testl %eax, %eax
    jnz F
    movl $-1, %eax
    jmp E
F:
    movw 20(%esp), %dx
    movw %dx, (%eax)
    movl %ebx, 4(%eax)
    movl %eax, (%esi)
    xorl %eax, %eax
E:
    addl $4, %esp
    popl %ebx
    popl %esi
    ret
