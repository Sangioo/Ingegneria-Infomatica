.globl my_strlen

my_strlen:
    movl 4(%esp), %ecx
    xorl %eax, %eax
L:
    cmpb $0, (%ecx)
    jz E
    incl %ecx
    incl %eax
    jmp L
E:
    ret
