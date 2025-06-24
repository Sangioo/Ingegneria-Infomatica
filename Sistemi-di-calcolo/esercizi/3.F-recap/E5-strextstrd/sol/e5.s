# callee-save-regs, caller-with-parms, idiv, loop

.globl strextstrd

strextstrd:  #char* strextstrd(const char *S, int STRIDE) {
    pushl %esi
    pushl %edi
    pushl %ebx
    pushl %ebp
    subl $4, %esp                       # prologo

    movl 24(%esp), %esi                 # const char* si = S;
    movl 28(%esp), %edi                 # int di = STRIDE;

    # Callee-save:
    # si=S, di=STRIDE, bp=n, b=b

    movl %esi, (%esp)                   #                 si
    call strlen                         # int bp = strlen(|);
    movl %eax, %ebp
    movl %ebp, %eax                     # int EDXEAX = bp;
    movl %eax, %edx                     #
    sarl $31, %edx                      #
    idiv %edi                           # int a1 = EDXEAX / di;
    incl %eax                           # a1++;
    movl %eax, (%esp)                   #                  a1
    call malloc                         # char* a = malloc(|);
    movl %eax, %ebx                     # char* b = a;
    testl %ebx, %ebx                    # if (b == NULL)
    je E                                # goto E;
    xorl %ecx, %ecx                     # int c = 0;
L:  cmpl %ebp, %ecx                     # if (c>=bp)
    jge F                               # goto F;
    movb (%esi, %ecx), %dl              # char d = si[c]
    movb %dl, (%ebx)                    # *b = d;
    addl %edi, %ecx                     # c += di;
    incl %ebx                           # b++;
    jmp L                               # goto L;
F:  movb $0, (%ebx)                     # *b = 0;

E:  addl $4, %esp                       # epilogo
    popl %ebp
    popl %ebx
    popl %edi
    popl %esi
    ret                                 # return a;
