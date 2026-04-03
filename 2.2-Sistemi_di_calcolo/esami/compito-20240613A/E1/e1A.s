.globl deleetify

deleetify:
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $4, %esp

    movl 20(%esp), %ebx
    xorl %edi, %edi
    movl 24(%esp), %ecx
    movl %ecx, (%esp)
    call malloc
    movl %eax, %esi

L:
    cmpl 24(%esp), %edi
    jae E

    cmpb $57, (%ebx, %edi, 1)
    jbe ELSE
    movb (%ebx, %edi, 1), %cl
    movb %cl, (%esi, %edi, 1)
    jmp FI
ELSE:
    movb (%ebx, %edi, 1), %cl
    movb %cl, (%esp)
    call deleetify_helper
    movb %al, (%esi, %edi, 1)
FI:
    incl %edi
    jmp L
E:
    movl %esi, %eax

    addl $4, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret
