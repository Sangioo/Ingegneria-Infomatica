.globl my_strcmp

my_strcmp:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx

F:
    cmpb $0, (%ecx)
    je E
    movb (%ecx), %al
    cmpb %al, (%edx)
    jne E
    incl %ecx
    incl %edx
    jmp F
E:
    movb (%ecx), %al
    subb (%edx), %al
    ret
