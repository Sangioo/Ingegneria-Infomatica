.globl deleetify

deleetify:
    pushl %ebx
    pushl %esi
    pushl %edi
    subl $12, %esp

    movl 28(%esp), %ebx
    movl 36(%esp), %esi
    xorl %edi, %edi
L:
    cmpl 32(%esp), %edi
    jae E

    cmpb $57, (%ebx, %edi, 1)
    jbe ELSE
    movb (%ebx, %edi, 1), %cl
    movb %cl, (%esi, %edi, 1)
    jmp FI
ELSE:
    movb (%ebx, %edi, 1), %cl
    movb %cl, (%esp)
    leal 8(%esp), %ecx
    movl %ecx, 4(%esp)
    call deleetify_helper
    movb 8(%esp), %cl
    movb %cl, (%esi, %edi, 1)
FI:
    incl %edi
    jmp L
E:

    addl $12, %esp
    popl %edi
    popl %esi
    popl %ebx
    ret
