.globl f

f:      # int f(int x, int y) {
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $8, %esp

    movl 24(%esp), %ebx         # int b = x;
    movl 28(%esp), %edi         # int di = y;
    movl %ebx, (%esp)
    movl %edi, 4(%esp)
    call g                      # int a = g(b, di);
    movl %eax, %esi             # int si = a;
    movl %edi, (%esp)
    movl %ebx, 4(%esp)
    call g                      # a = g(di, b);
    addl %esi, %eax             # a = a + si;

    addl $8, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret             # return a;
