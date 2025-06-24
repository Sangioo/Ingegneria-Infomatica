.globl num_vowels

num_vowels:  
    pushl %ebx             # prologo
    pushl %edi
    subl $4, %esp

    movl 16(%esp), %ebx    # char *b = s;
    xorl %edi, %edi        # int di = 0;
L:  cmpb $0, (%ebx)        # if (*b == 0) 
    je E                   #     goto E;
    movsbl (%ebx), %eax    # int a = *b; // integer promotion
    movl %eax, (%esp)      # -------------\
    call is_vowel          # a = is_vowel(a); 
    addl %eax, %edi        # di = di + a;
    incl %ebx              # b++;
    jmp L                  # goto L;
E:  movl %edi, %eax        # a = di;

    addl $4, %esp          # epilogo
    popl %edi
    popl %ebx

    ret                    # return a;
