.globl cond_compute

cond_compute:
    # prologo
    pushl   %edi
    pushl   %ebx
    pushl   %ebp
    subl    $12, %esp

    movl    40(%esp), %edi
    movl    32(%esp), %ebp
    xorl    %ebx, %ebx

L:
    cmpl    36(%esp), %ebx
    jge     E

    movl    28(%esp), %edx
    movb    (%edx, %ebx, 1), %dl
    movb    %dl, (%edi, %ebx, 1)

    movl    (%ebp, %ebx, 4), %ecx
    testl   %ecx, %ecx
    je      T

    leal    8(%esp), %ecx
    movl    %ecx, 4(%esp)
    movsbl  %dl, %edx
    movl    %edx, (%esp)
    call    compute
    movb    8(%esp), %al
    movb    %al, (%edi, %ebx, 1) 

T:
    incl    %ebx
    jmp L

E:
    movl    %edi, %eax

    # epilogo
    addl    $12, %esp
    popl    %ebp
    popl    %ebx
    popl    %edi
    ret