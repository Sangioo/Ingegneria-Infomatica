.globl f
f: #int f(int x) {
    # prologo
    pushl %ebx
    pushl %edi
    subl $4, %esp
    #
    movl 16(%esp), %ebx # int b = x;
    movl %ebx, (%esp)
    call g              # int a = g(b);
    movl %eax, %edi     # int di = a;
    movl %ebx, (%esp)
    call h              # a = h(b);
    addl %edi, %eax     # a = di + a;
    # epilogo
    addl $4, %esp
    popl %edi
    popl %ebx
    # 
    ret             # return a;