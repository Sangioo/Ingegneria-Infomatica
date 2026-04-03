# void prod(short x, char y, int * res);
.globl check
check: # int check(short* a, char* b, unsigned n) {
    pushl %ebx
    pushl %esi
    pushl %edi
    subl $16, %esp      # int res;

    movl 32(%esp), %esi # short* esi = a;
    movl %esi, %ebx     # short* ebx = esi;
    movl 40(%esp), %ecx # unsigned ecx = n;
    movl 36(%esp), %edi # char* edi = b;

    addl %ecx, %ebx     # ebx = ebx + ecx;
    addl %ecx, %ebx
    subl $2, %ebx       # ebx = ebx - 1;
L:
    cmpl %esi, %ebx     # if (ebx < esi)
    jb E                # goto E;

    movswl (%ebx), %eax
    movl %eax, (%esp)
    movsbl (%edi), %eax
    movl %eax, 4(%esp)
    leal 12(%esp), %eax
    movl %eax, 8(%esp)
    call prod           # prod(*ebx, *edi, &res);
    cmpl $6, 12(%esp)   # if (res != 6)
    jne F               # goto F;
    movl $1, %eax
    jmp E2
F:
    subl $2, %ebx       # ebx--;
    incl %edi           # edi++;
    jmp L               # goto L;
E:
    movl $0, %eax
E2:
    addl $16, %esp
    popl %edi
    popl %esi
    popl %ebx
    ret # return 0;
