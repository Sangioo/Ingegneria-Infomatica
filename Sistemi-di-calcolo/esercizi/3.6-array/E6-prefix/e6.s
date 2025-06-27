.globl is_prefix

is_prefix:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
L:
    cmpb $0, (%ecx)
    je E
    cmpb $0, (%edx)
    je E
    movb (%ecx), %al
    cmpb %al, (%edx)
    jne E
    incl %ecx
    incl %edx
    jmp L
E:
    cmpb $0, (%ecx)
    sete %al
    movsbl %al, %eax
    ret
