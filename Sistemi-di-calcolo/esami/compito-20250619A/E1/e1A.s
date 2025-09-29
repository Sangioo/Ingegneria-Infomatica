.globl fight

fight:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $12, %esp

    movl 32(%esp), %ecx
    movw (%ecx), %di
    movl 36(%esp), %edx
    movw (%edx), %si
    xorb %bl, %bl
    movb $1, %bh
L:
    cmpb $10, %bh
    jae E
    movb %bh, (%esp)
    movl 32(%esp), %ecx
    movl %ecx, 4(%esp)
    movw %si, 8(%esp)
    call update
    movw %ax, %si
    movb %bh, (%esp)
    movl 36(%esp), %ecx
    movl %ecx, 4(%esp)
    movw %di, 8(%esp)
    call update
    movw %ax, %di
    movw %di, (%esp)
    movw %si, 4(%esp)
    call winner
    movb %al, %bl
    testb %bl, %bl
    jge E
    xorb %bl, %bl
    incb %bh
    jmp L
E:
    movzbl %bl, %eax

    addl $12, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
