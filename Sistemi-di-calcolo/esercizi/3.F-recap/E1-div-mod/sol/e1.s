.globl div_mod

div_mod:  # void div_mod(int X, int Y, int* Q, int* R) {
    movl 4(%esp), %eax      # int a = X;
    movl %eax, %edx         # int d = a (useless in C);
    sarl $31, %edx          # 0/1 extension of %eax into %edx (useless in C)
    idivl 8(%esp)           # d = a % Y | a = a / Y
    movl 12(%esp), %ecx     # c = Q  -- write back
    movl %eax, (%ecx)       # *c = a;
    movl 16(%esp), %ecx     # c = R
    movl %edx, (%ecx)       # *c = d;
    ret
