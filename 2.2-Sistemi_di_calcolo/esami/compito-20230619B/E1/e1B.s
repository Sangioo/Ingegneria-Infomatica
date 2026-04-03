.globl rc4_encrypt_rev

rc4_encrypt_rev:
    pushl %esi
    pushl %edi
    pushl %ebx
    pushl %ebp
    subl $12, %esp

    movl 36(%esp), %esi
    movl %esi, (%esp)
    call strlen
    addl %eax, %esi
    decl %esi

    movl 40(%esp), %ebp

    xorl %edi, %edi
    xorb %bl, %bl
L:
    cmpl 36(%esp), %esi
    jb E

    movl %edi, %ecx
    incl %ecx
    andl $255, %ecx
    movl %ecx, %edi

    movl 32(%esp), %ecx
    addb (%ecx, %edi, 1), %bl

    movl %ecx, (%esp)
    movl %edi, 4(%esp)
    movb %bl, 8(%esp)
    call rc4_helper
    xorb (%esi), %al
    movb %al, (%ebp)
    decl %esi

    incl %ebp

    jmp L
E:
    addl $12, %esp
    popl %ebp
    popl %ebx
    popl %edi
    popl %esi
    ret
