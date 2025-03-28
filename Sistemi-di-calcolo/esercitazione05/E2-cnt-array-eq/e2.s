.globl counteq

counteq:
    pushl %edi
    pushl %esi
    pushl %ebx

    xorl %eax, %eax
    movl 16(%esp), %edi
    movl 20(%esp), %esi
    movl 24(%esp), %edx
    decl %edx
E:
    cmpl $0, %edx
    jl F
    movw (%edi, %edx, 2), %bx
    movw (%esi, %edx, 2), %cx
    cmpw %bx, %cx
    jne G
    incl %eax
G:
    decl %edx
    jmp E
F:
    popl %ebx
    popl %esi
    popl %edi
    ret
