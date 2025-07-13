.globl has_duplicates

has_duplicates:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp

    movl 20(%esp), %ebx
    movl 24(%esp), %ebp
    xorl %eax, %eax
    xorl %edi, %edi
L1:
    cmpl %ebp, %edi
    jae E1
    leal 1(%edi), %esi
L2:
    cmpl %ebp, %esi
    jae E2
    movw (%ebx, %edi, 2), %cx
    movw (%ebx, %esi, 2), %dx
    cmpw %cx, %dx
    jne FI
    movl $1, %eax
FI:
    incl %esi
    jmp L2
E2:
    incl %edi
    jmp L1
E1:

    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
