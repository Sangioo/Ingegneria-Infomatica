.globl adler32
adler32:    # unsigned adler32(unsigned char *data, unsigned len) {
    pushl %esi
    pushl %edi
    pushl %ebx
    pushl %ebp
    subl $8, %esp
    movl 28(%esp), %esi         #     unsigned char* esi = data;
                                # 
    xorl %eax, %eax             #     unsigned eax = 0;
    testl %esi, %esi            #     if (esi == NULL)
    je E2                       #         goto E;
    cmpl $0, 32(%esp)           #     if (len == 0)
    je E2                       #         goto E;
                                # 
    movl $1, %ebp               #     unsigned ebp = 1
    xorl %edi, %edi             #     unsigned edi = 0;
                                #     
                                #     unsigned k;
    leal 4(%esp), %ecx
    movl %ecx, (%esp)
    call get_addler_constant    #     get_addler_constant(&k);
                                # 
    xorl %ebx, %ebx             #     int ebx = 0;
L:
    cmpl 32(%esp), %ebx         #     if (ebx >= len) goto E;
    jae E
    movzbl (%esi, %ebx), %eax   #     eax = ebp + esi[ebx];
    addl %ebp, %eax
    xorl %edx, %edx             #     unsigned edx = 0;
    movl 4(%esp), %ecx          #     unsigned ecx = k;
    divl %ecx                   #     ebp = eax % ecx;
    movl %edx, %ebp
    movl %ebp, %eax
    addl %edi, %eax             #     eax = edi + ebp;
    xorl %edx, %edx             #     edx = 0;
    divl %ecx                   #     edi = eax % ecx;
    movl %edx, %edi
    incl %ebx                   #     ++ebx;
    jmp L                       #     goto L;
E:
    movl %edi, %eax
    shll $16, %eax
    orl %ebp, %eax              #     eax = (edi << 16) | ebp;
E2:
    addl $8, %esp
    popl %ebp
    popl %ebx
    popl %edi
    popl %esi
    ret                         #     return eax;
