.globl check

check:
    pushl %ebx
    pushl %ebp
    subl $4, %esp

    movl 16(%esp), %ebp
    xorw %bx, %bx
L:
    testl %ebp, %ebp
    jz E
    incb %bh
    movl %ebp, (%esp)
    call is_valid_move
    testb %al, %al
    jz F
    incb %bl
F:
    movl 12(%ebp), %ebp
    jmp L
E:
    cmpb %bh, %bl
    sete %al

    addl $4, %esp
    popl %ebp
    popl %ebx
    ret
