.globl max
max:
    movl 4(%esp), %ecx  # int c = x;
    movl 8(%esp), %edx  # int d = y;
                        # int a;
    cmpl %edx, %ecx     # if (c<=d) 
    jle F               # goto F;
    movl %ecx, %eax     # a = c;
    jmp E               # goto E;
F:
    movl %edx, %eax     # a = d;
E:
    ret                 # return a;