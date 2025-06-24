.globl fact
fact:
    movl $1, %eax   # unsigned a = 1, c;
    movl $2, %ecx   # c = 2;
L:
    cmpl 4(%esp), %ecx  # if (c > n) 
    ja E                # goto E;
    imull %ecx, %eax    # a *= c;   # POTENZIALMENTE SBAGLIATO 
                                    # QUANDO VARIABILE C E' (UNSIGNED) LONG LONG 
    # alternativa con uso MUL:
    # mull %ecx         # a *= c; 
    incl %ecx           # ++c;
    jmp L               # goto L;
E:
    ret                 # return a;