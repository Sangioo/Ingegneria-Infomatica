.globl f

f:
    movl 4(%esp), %eax   # int a = x;
    imull 8(%esp), %eax  # a = a * y;
    movl 12(%esp), %ecx  # int c = z;
    imull 16(%esp), %ecx # c = c * w;
    addl %ecx, %eax      # a = a + c;
    ret                  # return a;
    