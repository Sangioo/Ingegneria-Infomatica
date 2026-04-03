.globl hextodec_sum

hextodec_sum:
    pushl %ebx
    pushl %ebp
    pushl %edi
    pushl %esi
    subl $12, %esp

    movl 32(%esp), %ebx
    movl 36(%esp), %ebp
    xorl %edi, %edi
    xorl %esi, %esi
L:
    cmpb $0, (%ebx)
    je E
    movl %ebx, (%esp)
    leal 8(%esp), %ecx
    movl %ecx, 4(%esp)
    call hextodec_helper
    cmpl $0, 8(%esp)
    jle FI
    addl 8(%esp), %esi
FI:
    movl 8(%esp), %ecx
    movl %ecx, (%ebp, %edi, 4)
    incl %edi
    addl $2, %ebx
    jmp L
E:
    movl %esi, %eax

    addl $12, %esp
    popl %esi
    popl %edi
    popl %ebp
    popl %ebx
    ret
