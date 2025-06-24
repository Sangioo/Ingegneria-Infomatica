.global my_strlen

my_strlen: # unsigned my_strlen(const char* s) {
    movl 4(%esp), %ecx       # const char* c = s;
    xorl %eax, %eax          # unsigned a = 0;
L:  movw (%ecx), %dl         # char d = *c;
    incl %ecx                # c++;
    testb %dl, %dl           # if (d==0)
    je E                     # goto E;
    incl %eax                # a++;
    jmp L                    # goto L;
E:  ret                      # return a;
