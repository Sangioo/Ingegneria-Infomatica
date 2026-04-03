.globl num_vowels

num_vowels:
    subl $4, %esp
    movl 8(%esp), %ecx
    xorl %edx, %edx
L:
    cmpb $0, (%ecx)
    je E
    movb (%ecx), %al
    movb %al, (%esp)
    call is_vowel
    addl %eax, %edx
    incl %ecx
    jmp L
E:
    movl %edx, %eax
    addl $4, %esp
    ret
