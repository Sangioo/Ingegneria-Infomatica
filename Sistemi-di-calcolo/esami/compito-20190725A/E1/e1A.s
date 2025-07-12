.globl most_freq_char

most_freq_char:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $8, %esp

    movl 32(%esp), %edi
    movl %edi, (%esp)
    movl $256, 4(%esp)
    call clear
    movl 28(%esp), %esi
L1:
    cmpb $0, (%esi)
    je E1
    movsbl (%esi), %ecx
    incl %esi
    incl (%edi, %ecx, 4)
    jmp L1
E1:
    xorl %ecx, %ecx
    xorl %eax, %eax
L2:
    cmpl $256, %ecx
    jge E2
    movl (%edi, %ecx, 4), %edx
    movl (%edi, %eax, 4), %ebx
    cmpl %ebx, %edx
    jle FI
    movl %ecx, %eax
FI:
    incl %ecx
    jmp L2
E2:

    addl $8, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
