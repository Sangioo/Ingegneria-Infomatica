.globl max

max: # int max(int X, int Y) {
    movl 4(%esp), %eax          # int a = X;
    movl 8(%esp), %ecx          # int c = Y;
    cmpl %eax, %ecx             # if (c > a)
    cmovgl %ecx, %eax           #    a = c;
    ret                         # return a;
