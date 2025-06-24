.globl f

f:
    pushl %ebx                  #     unsigned b;
    pushl %edi
    pushl %esi
    subl $8, %esp
    movl 24(%esp), %edi         #     int* di = v;
    movl 28(%esp), %esi         #     unsigned si = n;
    movl $1, %ebx               #     b = 1;
L1: cmpl %esi, %ebx             # L1: if (b>=si)
    jae L2                      #         goto L2;
    movl -4(%edi,%ebx,4),%ecx   #     int c = di[b-1];
    movl (%edi,%ebx,4),%edx     #     int d = di[b];
    movl %ecx, (%esp)
    movl %edx, 4(%esp)
    call ordinati               #     int a = ordinati(c,d);
    testl %eax, %eax            #     if (a == 0)
    je L3                       #         goto L3;
    incl %ebx                   #     b++;
    jmp L1                      #     goto L1;
L3: xorl %eax, %eax             # L3: a = 0;
    jmp E                       #     goto E;
L2: movl $1, %eax               # L2: a = 1;
E:  addl $8, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret                         # E:  return a;
