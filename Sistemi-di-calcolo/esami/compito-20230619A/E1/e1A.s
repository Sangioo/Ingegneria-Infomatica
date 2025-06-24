.globl rc4_encrypt

rc4_encrypt:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $20, %esp
    
    xorl %edi, %edi
    xorl %esi, %esi
    xorl %ebx, %ebx
    movl 44(%esp), %ebp
L:
    cmpb $0, (%ebp)
    jz E

    movl %edi, %eax
    incl %eax
    andl $255, %eax
    movl %eax, %edi

    movl 40(%esp), %ecx
    addb (%ecx, %edi, 1), %bl

    movl %ecx, (%esp)
    movl %edi, 4(%esp)
    movb %bl, 8(%esp)
    leal 16(%esp), %edx
    movl %edx, 12(%esp)
    call rc4_helper

    movl 48(%esp), %ecx
    movb 16(%esp), %dl
    movb %dl, (%ecx, %esi, 1)
    movb (%ebp), %dh
    xorb %dh, (%ecx, %esi, 1)

    incl %esi
    incl %ebp

    jmp L
E:

    addl $20, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
