.globl f
f:
    # SOLUZIONE CON USO DI EBX
    pushl %ebx          # prologo
    subl $4, %esp       # spazio per parametri g e h

    movl 12(%esp), %ecx # int c = x;
    movl %ecx, (%esp)   # ecx -----\
    call g              # int a = g(c);
    movl %eax, %ebx     # int b = a;
    call h              # a = h(c); // stesso parametro di g
    addl %ebx, %eax     # a = a + b;

    addl $4, %esp       # epilogo
    popl %ebx

    ret                 # return a;
