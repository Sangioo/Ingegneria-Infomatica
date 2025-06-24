.global sum
sum: # short sum(short* v, int n) {
    movl 4(%esp), %ecx        # short* c = v;
    movl 8(%esp), %edx        # int d = n;
    xorw %ax, %ax             # short a = 0;
    decl %edx                 # d--;
L:  testl %edx, %edx          # if (d<0)
    jl E                      # goto E;
    addw (%ecx, %edx, 2), %ax # a = a + c[d];
    decl %edx                 # d--;
    jmp L                     # goto L;
E:  ret                       # return a;
