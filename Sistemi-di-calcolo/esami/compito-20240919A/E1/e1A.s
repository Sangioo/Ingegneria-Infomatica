.globl slice

slice:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $12, %esp

    movl 32(%esp), %ebx
    movl 44(%esp), %esi
    xorl %edi, %edi
    movl 40(%esp), %ebp
    subl 36(%esp), %ebp
    decl %ebp
L:
    cmpb $0, (%ebx)
    je E

    cmpl 36(%esp), %edi
    jne FI
    movl %ebx, (%esp)
    movl %ebp, 4(%esp)
    movl %esi, 8(%esp)
    call slice_helper
FI:
    incl %edi
    incl %ebx

    jmp L
E:
    cmpl 36(%esp), %edi
    jge F
    xorl %ebp, %ebp
F:
    movl %ebp, %eax

    addl $12, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
