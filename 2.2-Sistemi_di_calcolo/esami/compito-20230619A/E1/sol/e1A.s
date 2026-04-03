.globl rc4_encrypt

rc4_encrypt:
    # prologo
    pushl   %edi
    pushl   %esi
    pushl   %ebx
    pushl   %ebp

    subl    $20, %esp               # alloca spazio per la call e rnd

    # codice 
    xorl    %edi, %edi              # int n = 0;
    xorl    %esi, %esi              # int i = 0;
    xorb    %bl, %bl                # unsigned char j = 0;

    movl    44(%esp), %ebp

L:
    cmpb    $0, (%ebp)              # if (*pt == 0)
    je      E                       # goto E;

    incl    %esi                    # i = i + 1;
    andl    $255, %esi              # i = i & 255;

    movl    40(%esp), %eax
    movb    (%eax, %esi, 1), %cl    # cl = sbox[i];
    addb    %cl, %bl                # j = j + cl;

    movl    %eax, (%esp)
    movl    %esi, 4(%esp)
    movb    %bl, 8(%esp)
    leal    16(%esp), %eax          # eax = &rnd;
    movl    %eax, 12(%esp)  
    call    rc4_helper              # rc4_helper(sbox, i, j, &rnd);

    movl    48(%esp), %eax          # eax = ct
    movb    (%ebp), %cl             # cl = *pt;
    xorb    16(%esp), %cl           # cl = cl ^ rnd;
    movb    %cl, (%eax, %edi, 1)    # ct[n] = cl;

    incl    %edi                    # n++;
    incl    %ebp                    # pt++;
    jmp     L                       # goto L;

E:
    # epilogo
    addl    $20, %esp

    popl    %ebp
    popl    %ebx
    popl    %esi
    popl    %edi
    ret
