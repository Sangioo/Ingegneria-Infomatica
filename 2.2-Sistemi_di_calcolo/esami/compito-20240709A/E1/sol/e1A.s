.globl cond_compute

cond_compute:
    # prologo
    pushl   %edi
    pushl   %ebx
    pushl   %ebp
    subl    $4, %esp

    movl    32(%esp), %edi
    movl    24(%esp), %ebp
    xorl    %ebx, %ebx

L:
    cmpl    28(%esp), %ebx
    jge     E

    movl    (%ebp, %ebx, 4), %ecx
    testl   %ecx, %ecx
    jne     F

    movl    20(%esp), %edx
    movw    (%edx, %ebx, 2), %dx
    movw    %dx, (%edi, %ebx, 2)
    jmp T

F:
    movl    20(%esp), %edx
    movw    (%edx, %ebx, 2), %dx
    movswl  %dx, %edx
    movl    %edx, (%esp)
    call    compute
    movw    %ax, (%edi, %ebx, 2) 

T:
    incl    %ebx
    jmp L

E:
    movl    %edi, %eax

    # epilogo
    addl    $4, %esp
    popl    %ebp
    popl    %ebx
    popl    %edi
    ret