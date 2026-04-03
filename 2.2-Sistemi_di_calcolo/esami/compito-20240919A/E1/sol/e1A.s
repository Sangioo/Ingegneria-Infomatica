.globl slice

slice:
    pushl   %ebx
    pushl   %edi
    pushl   %esi
    subl    $12, %esp

    xorl    %ebx, %ebx              # int rbx = 0;
    movl    28(%esp), %edi          # char* edi = str;

    movl    36(%esp), %esi          # int esi = end
    subl    32(%esp), %esi          # - start
    decl    %esi                    # - 1;

L:
    movb    (%edi), %cl             # char cl = *edi;
    testb   %cl, %cl                # if (*edi == 0)
    je      E                       # goto E;

    cmpl    32(%esp), %ebx          # if (ebx != start)
    jne     F                       # goto F;

    movl    %edi, (%esp)
    movl    %esi, 4(%esp)
    movl    40(%esp), %ecx
    movl    %ecx, 8(%esp)
    call    slice_helper            # slice_helper(edi, esi, res);
    
F:
    incl    %ebx                    # ebx++;
    incl    %edi                    # edi++;
    jmp     L                       # goto L;

E:
    movl    %esi, %eax              # int eax = esi;
    cmpl    36(%esp), %ebx          # if (ebx >= start)
    jge     R                       # goto R;
    xorl    %eax, %eax              # eax = 0;

R:
    addl    $12, %esp
    popl    %esi
    popl    %edi
    popl    %ebx
    ret
