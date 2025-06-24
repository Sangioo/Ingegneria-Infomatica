.globl base64lessless

base64lessless:    # unsigned char* base64lessless(unsigned char *data, unsigned out_len, unsigned char* b64_table) {
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp
    xorl %eax, %eax     # unsigned char* eax = NULL;
    movl 24(%esp), %esi # unsigned char* esi = data;
    testl %esi, %esi    # if (esi == NULL) goto E;
    je E
    cmpl $0, 28(%esp)   # if(out_len == 0) goto E;
    je E
    movl 28(%esp), %eax
    movl %eax, (%esp)
    call malloc         # eax = malloc(out_len);
    xorb %dl, %dl       # unsigned char dl = 0; // bits_left
    xorb %dh, %dh       # unsigned char dh = 0; // prev_bits
                        # unsigned char cl, ch; // temp
    xorl %edi, %edi     # int edi = 0; // i
L:
    cmpl 28(%esp), %edi # if (edi >= out_len) goto E;
    jge E
    movb $6, %cl        # cl = 6;
    subb %dl, %cl       # cl -= dl;
    movb %dh, %bl       # unsigned char bl = dh; 
    shlb %cl, %bl       # bl = bl << cl;
    movb %dl, %cl       # cl = dl;
    movb (%esi), %ch    # ch = *esi;
    shrb %cl, %ch       # ch = ch >> cl;
    shrb $2, %ch        # ch = ch >> 2;
    orb %ch, %bl        # bl = bl | ch;
    movb $8, %cl        # cl = 8;
    subb $6, %cl        # cl = cl - 6;
    addb %dl, %cl       # cl = cl + dl;
    andb $7, %cl        # cl = cl & 7;
    movb %cl, %dl       # dl = cl;
    movb $8, %cl        # cl = 8;
    subb %dl, %cl       # cl = cl - dl;
    movb (%esi), %dh    # dh = *esi;
    shlb %cl, %dh       # dh = dh << cl;
    shrb %cl, %dh       # dh = dh >> cl;
# 
    cmpb $6, %dl        # if (dl >= 6) goto F;
    jae F
    incl %esi           # esi += 1;
F:
    movl 32(%esp), %ecx 
    movzbl %bl, %ebx
    movb (%ecx, %ebx), %cl    
    movb %cl, (%eax, %edi)  # eax[edi] = b64_table[bl];
    incl %edi               # edi += 1;
    jmp L                   # goto L;
E:
    addl $4, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret             # return eax;
