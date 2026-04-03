.globl f
f:
    call g      # int a = g();
    incl %eax   # a = a + 1;
    ret         # return a;