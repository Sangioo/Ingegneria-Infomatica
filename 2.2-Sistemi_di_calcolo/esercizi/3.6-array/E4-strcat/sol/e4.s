.global my_strcat
my_strcat: # char* my_strcat(char* dest, const char* src) {
    movl 4(%esp), %edx     # char* d = dest;
    movl 8(%esp), %ecx     # const char* c = src;
L:  cmpb $0,(%edx)         # if (*d==0)
    je E                   # goto E;
    incl %edx              # d++;
    jmp L                  # goto L;
E:  movb (%ecx), %al       # ; char al = *c;
    movb %al, (%edx)       # *d = al;
    testb %al, %al         # if (al==0)
    je F                   # goto F;
    incl %edx              # d++;
    incl %ecx              # c++;
    jmp E                  # goto E;
F:  movl 4(%esp), %eax     # ; char* a = dest;
    ret                    # return a;

