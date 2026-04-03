.globl div_vectors

div_vectors: # unsigned int* reverse_div_vectors(unsigned int* a, unsigned int* b, int n) {
    pushl %ebx
    pushl %esi
    pushl %edi
    pushl %ebp
    subl $4, %esp
    movl 24(%esp), %edi     # edi = a
    movl 28(%esp), %ebp     # ebp = b
    cmpl $0, %edi           # if (a == NULL)
    je E2                   #     goto E2;
    cmpl $0, %ebp           # if (b == NULL)
    je E2                   #     goto E2;
    cmpl $0, 32(%esp)       # if (n == 0)
    je E2                   #     goto E2;
    movl $4, %eax           # int l = 4; // sizeof(int)
    imull 32(%esp), %eax    # l = l * n;
    movl %eax, (%esp)
    call malloc             # int* out = malloc(l);
    movl %eax, %ebx         
    xorl %esi, %esi         # int i = 0;
L:
    cmpl 32(%esp), %esi         # if (i >= n) goto E;
    jge E1
    movl (%edi, %esi, 4), %eax  # int eax = a[i];
    xorl %edx, %edx             # int edx = 0;
    movl (%ebp, %esi, 4), %ecx  # int ecx = b[j];
    idivl %ecx                  # eax = eax / ecx; // usare idiv
    movl %eax, (%ebx, %esi, 4)  # out[i] = eax;
    incl %esi                   # i += 1;
    jmp L                       # goto L;
E1:
    movl %ebx, %eax             # int* eax2 = out;
    jmp E3
E2:
    xorl %eax, %eax             # eax2 = NULL;
E3:
    addl $4, %esp
    popl %ebp
    popl %edi
    popl %esi
    popl %ebx
    ret                 # return eax2;
