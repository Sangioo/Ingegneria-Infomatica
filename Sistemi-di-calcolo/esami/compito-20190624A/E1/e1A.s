.globl init_matrix

init_matrix:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $8, %esp

    movl 28(%esp), %ebx
    xorl %edi, %edi
L1:
    cmpl 32(%esp), %edi
    jae E1
    xorl %esi, %esi
L2:
    cmpl 32(%esp), %esi
    jae E2
    movl %edi, (%esp)
    movl %esi, 4(%esp)
    call value
    movl (%ebx, %edi, 4), %ecx
    movw %ax, (%ecx, %esi, 2)
    incl %esi
    jmp L2
E2:
    incl %edi
    jmp L1
E1:

    addl $8, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
