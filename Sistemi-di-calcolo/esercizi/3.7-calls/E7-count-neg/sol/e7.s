.globl f

f:
    pushl %edi                  # prologo
    pushl %esi
    pushl %ebx
    pushl %ebp
    subl $4, %esp

    movl 24(%esp), %edi         # int* di = v;       // di <-> v
    movl 28(%esp), %esi         # unsigned si = n;   // si <-> n
    xorl %ebx, %ebx             # unsigned b = 0;    // b <-> i
    xorl %ebp, %ebp             # unsigned bp = 0;   // bp <-> cnt
L:  cmpl %esi, %ebx             # if (b >= si)
    jae E                       #     goto E;
    movl (%edi, %ebx, 4), %ecx  # int c = v[b];
    movl %ecx, (%esp)           # ------------------------\
    call is_negative            # unsigned a = is_negative(c);
    addl %eax, %ebp             # bp = bp + a;
    incl %ebx                   # b++;
    jmp L                       # goto L;
E:  movl %ebp, %eax             # a = bp;

    addl $4, %esp               # epilogo
    popl %ebp
    popl %ebx
    popl %esi
    popl %edi

    ret                         # return a;
