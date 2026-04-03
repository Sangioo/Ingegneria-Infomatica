.globl fact

fact:
    movl $1, %eax       # a = 1;
    movl 4(%esp), %edx  # d = n;
    movl $2, %ecx       # c = 2
L:  cmp %edx, %ecx      # if (c > d) 
    ja E                #     goto E;
    imull %ecx, %eax    # a = a * c;
    incl %ecx           # c++;
    jmp L               # goto L;
E:  ret                 # return a;
