.globl my_strcat

my_strcat:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
L1:
    cmpb $0, (%ecx)
    je E1
    incl %ecx
    jmp L1
E1:
    movb (%edx), %al
    movb %al, (%ecx)
    testb %al, %al
    je E2
    incl %ecx
    incl %edx
    jmp E1
E2:
    movl 4(%esp), %eax
    ret
