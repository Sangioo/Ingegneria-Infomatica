.globl is_suffix

is_suffix:
    pushl %edi
    pushl %esi
    pushl %ebx
    movl 16(%esp), %ecx
    movl %ecx, %edi
    movl 20(%esp), %edx
    movl %edx, %esi

W1:
    movb (%ecx), %al
    testb %al, %al
    jz W1BIS
    incl %ecx
    jmp W1
W1BIS:
    incl %ecx
W2:
    movb (%edx), %al
    testb %al, %al
    jz W2BIS
    incl %edx
    jmp W2
W2BIS:
    incl %edx

W3:
    cmpl %edi, %ecx
    jz END
    cmpl %esi, %edx
    jz END
    decl %ecx
    decl %edx
    movb (%ecx), %al
    cmpb %al, (%edx)
    jnz END
    jmp W3
END:
    cmpl %edi, %ecx
    setz %ah
    
    movb (%ecx), %bl
    cmpb %bl, (%edx)
    setz %al

    andb %ah, %al
    movsbl %al, %eax

    popl %ebx
    popl %esi
    popl %edi
    ret
