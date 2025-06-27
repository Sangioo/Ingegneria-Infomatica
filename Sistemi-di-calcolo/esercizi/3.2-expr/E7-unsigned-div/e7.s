.globl f
f:
    movl 4(%esp), %eax  # unsigned a = x;
    movl 8(%esp), %ecx  # unsigned c = y;
    movl $0, %edx       # unsigned d = 0; // d:a / c 
    divl %ecx           # a = a % c;
    ret                 # return a;
