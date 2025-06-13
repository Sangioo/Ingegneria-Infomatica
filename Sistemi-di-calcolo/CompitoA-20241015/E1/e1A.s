.globl cond_compute

cond_compute:
    pushl %ebx
    pushl %ebp
    pushl %edi
    pushl %esi
    subl $12, %esp

    movl 32(%esp), %ebx
    movl 36(%esp), %ebp
    movl 44(%esp), %esi
    xorl %edi, %edi

L:
    cmpl 40(%esp), %edi
    jge E

    movl (%ebx, %edi, 1), %ecx
    movl %ecx, (%esi, %edi, 1)

    cmpl $0, (%ebp, %edi, 4)
    jz FI
    movl (%esi, %edi, 1), %edx
    movl %edx, (%esp)
    leal 8(%esp), %edx
    movl %edx, 4(%esp)
    call compute
    movl 8(%esp), %ecx
    movl %ecx, (%esi, %edi, 1)
FI:
    incl %edi

    jmp L
E:
    movl %esi, %eax

    addl $12, %esp
    popl %esi
    popl %edi
    popl %ebp
    popl %ebx
    ret
