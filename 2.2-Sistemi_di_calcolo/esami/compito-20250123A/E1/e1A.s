.globl transform

transform:
    pushl %ebx
    pushl %ebp
    pushl %edi
    pushl %esi
    subl $8, %esp

    movl 28(%esp), %ebx
    movl 36(%esp), %ebp
    xorl %edi, %edi
    xorl %esi, %esi
L:
    cmpl 32(%esp), %edi
    jge E

    cmpl (%ebx, %edi, 4), %esi
    jle ELSE
    movl %esi, (%esp)
    leal 1(%edi), %ecx
    movl %ecx, 4(%esp)
    call average
    movl %eax, (%ebp, %edi, 4)
    jmp FI
ELSE:
    movl (%ebx, %edi, 4), %ecx
    movl %ecx, (%ebp, %edi, 4)
FI:
    addl (%ebx, %edi, 4), %esi
    incl %edi
    jmp L
E:
    movl %esi, %eax

    addl $8, %esp
    popl %esi
    popl %edi
    popl %ebp
    popl %ebx
    ret
