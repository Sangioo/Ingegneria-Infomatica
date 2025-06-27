.globl list_equal

list_equal:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx
L:
    testl %ecx, %ecx
    jz F
    testl %edx, %edx
    jz F
    movw (%edx), %ax
    cmpw (%ecx), %ax
    je E
    xorl %eax, %eax
    ret
E:
    movl 4(%ecx), %ecx
    movl 4(%edx), %edx
    jmp L
F:
    testl %ecx, %ecx
    setz %al
    testl %edx, %edx
    setz %ah
    andb %ah, %al
    movsbl %al, %eax
    ret
