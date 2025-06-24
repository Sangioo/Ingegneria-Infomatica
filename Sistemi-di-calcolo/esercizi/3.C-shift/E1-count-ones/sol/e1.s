.globl count1

count1:
    xorl %eax, %eax      # unsigned a = 0;
    movl 4(%esp), %ecx   # unsigned c = n;
L:  testl %ecx, %ecx     # if (c)
    je E                 # goto E;
    testl $1, %ecx       # if ((c & 1)==0)
    je K                 # goto K;
    incl %eax            # a++;
K:  shrl %ecx            # c = c >> 1;
    jmp L                # goto L;
E:  ret                  # return a;
