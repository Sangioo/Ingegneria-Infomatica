.globl transform


transform:
    pushl   %esi
    pushl   %edi
    subl    $8, %esp

    xorl    %esi, %esi
    xorl    %edi, %edi

L:
    cmpl    24(%esp), %esi
    jae     E

    movl    20(%esp), %ecx
    movl    (%ecx, %esi, 4), %eax

    cmpl    %eax, %edi
    jbe     F

    movl    %edi, (%esp)
    movl    %esi, %eax
    incl    %eax
    movl    %eax, 4(%esp)
    call    average
    
    movl    28(%esp), %ecx
    movl    %eax, (%ecx, %esi, 4)
    jmp     T

F:
    movl    20(%esp), %ecx
    movl    (%ecx, %esi, 4), %eax
    movl    28(%esp), %ecx
    movl    %eax, (%ecx, %esi, 4)

T:
    movl    20(%esp), %ecx
    movl    (%ecx, %esi, 4), %eax
    addl    %eax, %edi
    incl    %esi

    jmp     L

E:
    movl    %edi, %eax

    addl    $8, %esp
    popl    %edi
    popl    %esi
    ret