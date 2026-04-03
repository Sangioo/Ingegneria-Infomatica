.globl is_prefix

is_prefix: # int is_suffix(const char* s, const char* t)
    # s <-> ecx, t <-> edx
    movl 4(%esp), %ecx      # char *c = s;
    movl 8(%esp), %edx      # char *d = t;
L:  movb (%ecx), %al        # char a = *c;
    cmpb $0, %al            # if (a == 0)
    je E                    #     goto E;
    cmpb $0, (%edx)         # if (*d == 0)
    je E                    #     goto E;
    cmpb %al, (%edx)        # if (a != *d)
    jne E                   #     goto E;
    incl %ecx               # c++;
    incl %edx               # d++;
    jmp L                   # goto L;
E:
    # soluzione con MOVZ e SETcc
    # (verranno viste nelle prossime lezioni)
    # testb %al, %al
    # sete %al
    # movzbl %al, %eax        # return a == 0;
    # ret
    
    # soluzione alternativa
    testb %al, %al
    jne E2
    movl $1, %eax
    jmp F
E2:
    movl $0, %eax
F:
    ret
