.globl cond_compute

cond_compute:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp

    movl 24(%esp), %ebx
    movl 28(%esp), %esi
    movl 36(%esp), %ebp
    xorl %edi, %edi

L:
    cmpl 32(%esp), %edi
    jge E

    cmpl $0, (%esi, %edi, 4)
    jnz ELSE
    movw (%ebx, %edi, 2), %cx
    movw %cx, (%ebp, %edi, 2)
    jmp FI
ELSE:
    movw (%ebx, %edi, 2), %cx
    movw %cx, (%esp)
    call compute
    movw %ax, (%ebp, %edi, 2)
FI:
    incl %edi
    jmp L
E:
    movl %ebp, %eax

    addl $4, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
