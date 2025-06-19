.globl rc4_encrypt_rev

rc4_encrypt_rev:

    # prologo
    pushl   %edi
    pushl   %ebx
    pushl   %esi
    pushl   %ebp
    
    subl    $12, %esp

    # codice
    xorl    %edi, %edi              # unsigned int i = 0;
    xorb    %bl, %bl                # unsigned char j = 0;

    movl    36(%esp), %ebp          # unsigned char *pt_aux = pt;
    movl    40(%esp), %esi          # ct <-> esi

    movl    %ebp, (%esp)
    call    strlen                  # int eax = strlen(pt);

    addl    %eax, %ebp              # pt_aux += eax;
    decl    %ebp                    # pt_aux--;

L:  cmpl    36(%esp), %ebp
    jl      E 
    
    incl    %edi                    # i = i + 1;
    andl    $255, %edi              # i = i & 255;

    movl    32(%esp), %eax
    addb    (%eax, %edi, 1), %bl    # j = j + sbox[i];

    movl    %eax, (%esp)
    movl    %edi, 4(%esp)
    movb    %bl, 8(%esp)
    call    rc4_helper              # al = rc4_helper(sbox, i, j);

    movb    (%ebp), %ah             # ah = *pt_aux;
    movb    %al, (%esi)             # *ct = al;
    xorb    %ah, (%esi)             # *ct = *ct ^ ah;

    incl    %esi                    # ct++;
    decl    %ebp                    # pt_aux--;
    jmp     L                       # goto L;

E:

    # epilogo
    addl    $12, %esp

    popl   %ebp
    popl   %esi
    popl   %ebx
    popl   %edi
    ret