.globl sqr

sqr:
    movl 4(%esp), %eax  # int a = x;
    imull %eax, %eax    # a = a * a;
    ret                 # return a;
