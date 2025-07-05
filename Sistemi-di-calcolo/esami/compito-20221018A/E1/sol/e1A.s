.globl str_to_upper 
str_to_upper: # char* str_to_upper(const char* s)
    pushl %ebx
    pushl %esi
    subl $4, %esp
    xorl %esi, %esi         # char* res = NULL;
    movl 16(%esp), %ebx
    testl %ebx, %ebx        # if (s == NULL) 
    je E                    # goto E;
    movl %ebx, (%esp)
    call strdup             # char* res = strdup(s); 
    movl %eax, %esi
    movl %eax, %ebx         # char* copy = res;
L:
    cmpb $0, (%ebx)         # if (*copy == 0) 
    je E                    # goto E;
    movsbl (%ebx), %eax
    movl %eax, (%esp)    
    call toupper            # char c = toupper(*copy); 
    movb %al, (%ebx)        # *copy = c;
    incl %ebx               # copy++;
    jmp L                   # goto L;
E:
    movl %esi, %eax
    addl $4, %esp
    popl %esi
    popl %ebx
    ret                     # return res;
