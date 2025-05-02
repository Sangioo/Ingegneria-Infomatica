.globl count_digits

count_digits:
    xorl %eax, %eax
    movl 4(%esp), %ecx
E:
    cmpb $0, (%ecx)
    je F

    cmpb $48, (%ecx)
    jl G
    cmpb $57, (%ecx)
    jg G
    incl %eax
G:
    incl %ecx
    jmp E
F:
    ret
