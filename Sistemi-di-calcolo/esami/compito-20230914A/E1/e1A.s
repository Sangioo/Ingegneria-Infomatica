.globl base64lessless

base64lessless:
    pushl %ebx
    pushl %ebp
    pushl %edi
    pushl %esi
    subl $4, %esp
    xorl %eax, %eax
    movl 24(%esp), %esi
    testl %esi, %esi
    jz E
    cmpl $0, 28(%esp)
    jz E
    movl 28(%esp), %eax
    movl %eax, (%esp)
    call malloc         # out = %eax

    xorl %edx, %edx     # prev_bits = %dh, bits_left = %dl
    xorl %edi, %edi     # i = %edi
L:
    cmpl 28(%esp), %edi
    jae E

    # unsigned char index = (prev_bits << (6 - bits_left));
    movb $6, %cl
    subb %dl, %cl
    movb %dh, %bl
    shlb %cl, %bl       # index = %bl

    # index = index | (item >> (2 + bits_left));
    movb $2, %cl
    addb %dl, %cl
    movb (%esi), %ch    # item = %ch
    shrb %cl, %ch
    orb %ch, %bl

    # bits_left = (8 - (6 - bits_left)) & 7;
    addb $2, %dl
    andb $7, %dl

    # unsigned char pos = (8 - bits_left);
    movb $8, %cl
    subb %dl, %cl

    # prev_bits = item << pos;
    movb (%esi), %dh
    shlb %cl, %dh
    
    # prev_bits = prev_bits >> pos;
    shrb %cl, %dh

    # if (bits_left < 6) data += 1;
    cmpb $6, %dl
    jae FI
    incl %esi
FI:

    # out[i] = b64_table[index];
    movl 32(%esp), %ecx
    movzbl %bl, %ebx
    movb (%ecx, %ebx, 1), %cl
    movb %cl, (%eax, %edi, 1)

    incl %edi
    jmp L
E:
    addl $4, %esp
    popl %esi
    popl %edi
    popl %ebp
    popl %ebx
    ret
