.globl print_concat

print_concat:
    pushl %ebx
    pushl %edi
    subl $520, %esp

    movl 532(%esp), %ebx
    xorl %edi, %edi
    movb $0, 8(%esp)
L:
    cmpl 536(%esp), %edi
    jge E
    leal 8(%esp), %ecx
    movl %ecx, (%esp)
    movl (%ebx, %edi, 4), %ecx
    movl %ecx, 4(%esp)
    call strcat
    incl %edi
    jmp L
E:
    leal 8(%esp), %ecx
    movl %ecx, (%esp)
    call puts

    addl $520, %esp
    popl %edi
    popl %ebx
    ret
