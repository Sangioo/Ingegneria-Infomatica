.globl array_div

array_div:  // void array_div(const int *a, const int *b, div_rem_t *res, int n){

    pushl %edi
    pushl %esi
    pushl %ebx
    pushl %ebp

    // parms: n<->ebp, a<->edi, b<->esi, res<->ebx , ecx<->min,e ax <->max

    movl 20(%esp), %edi                                 # const int *edi = a;
    movl 24(%esp), %esi                                 # const int *esi = b;
    movl 28(%esp), %ebx                                 # div_rem_t *ebx = res;
    movl 32(%esp), %ebp                                 # int ebp=n;

                                                        # int ecx, eax;

L:  decl %ebp                                           # ebp--;
    testl %ebp, %ebp                                    # if (ebp < 0)
    jl E                                                #     goto E

    movl (%esi,%ebp,4), %ecx                            # ecx = esi[ebp];      // min
    cmpl (%edi,%ebp,4), %ecx                            # if (ecx > edi[ebp]);
    cmovgl (%edi,%ebp,4), %ecx                          #     ecx = edi[ebp];

    movl (%edi,%ebp,4), %eax                            # eax = edi[ebp];      // max
    cmpl (%esi,%ebp,4), %eax                            # if (eax <= esi[ebp])
    cmovlel (%esi,%ebp,4), %eax                         #     eax = esi[ebp];

    movl %eax, %edx                                     # movl %eax, %edx and
    sarl $31, %edx                                      # sarl $31, %edx are equivalent to instruction cltd
    idivl %ecx                                          # divide %edx:%eax by %ecx
    movl %eax, (%ebx, %ebp, 8)                          # ebx[ebp].quot = eax / ecx;
    movl %edx, 4(%ebx, %ebp, 8)                         # ebx[ebp].rem  = eax & ecx;

    jmp L                                               # goto L;

E:  popl %ebp
    popl %ebx
    popl %esi
    popl %edi
    ret
