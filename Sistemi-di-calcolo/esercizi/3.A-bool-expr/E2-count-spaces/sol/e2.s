.global count_spaces

count_spaces:
    movl 4(%esp),%ecx         # const char *c = s;
    xorl %eax, %eax           # int a = 0;
                              # char dl;
L:  movb (%ecx), %dl          # dl = *c;
    testb %dl, %dl            # if (dl == 0) 
    je E                      #    goto E;
    cmpb $32, %dl
    sete %dl                  # dl = dl == 32;
    movzbl %dl, %edx          # int d = dl;
    addl %edx, %eax           # a += d;
    incl %ecx                 # c++;
    jmp L                     # goto L;
E:  ret                       # return a;

