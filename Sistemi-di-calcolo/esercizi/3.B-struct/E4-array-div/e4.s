.globl array_div

array_div:
    pushl %ebx
    pushl %edi
    movl 20(%esp), %edi
    xorl %ecx, %ecx
L:
    movl 12(%esp), %eax
    movl 16(%esp), %ebx

    cmpl 24(%esp), %ecx
    jge E

    movl (%eax, %ecx, 4), %edx
    cmpl (%ebx, %ecx, 4), %edx
    jl F
    movl (%ebx, %ecx, 4), %ebx
    movl (%eax, %ecx, 4), %eax
    jmp G
F:
    movl (%ebx, %ecx, 4), %edx
    movl (%eax, %ecx, 4), %ebx
    movl %edx, %eax
G:
    movl %eax, %edx
    sarl $31, %edx
    idiv %ebx
    movl %eax, (%edi, %ecx, 8)
    movl %edx, 4(%edi, %ecx, 8)

    incl %ecx
    jmp L
E:
    popl %edi
    popl %ebx
    ret
