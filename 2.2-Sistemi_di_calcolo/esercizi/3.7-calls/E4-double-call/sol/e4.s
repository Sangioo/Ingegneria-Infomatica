.globl f
f:
    # SOLUZIONE CON USO DI EBX
    #
    # (preferita perche' non altera ESP 
    # durante codice di f ad esclusione
    # di prologo ed epilogo)
    #
    pushl %ebx          # prologo
    call g              # int a = g();
    movl %eax, %ebx     # int b = a;
    call h              # int a = h();
    addl %ebx, %eax     # a = a + b;
    popl %ebx           # epilogo
    ret                 # return a;

    # SOLUZIONE CON USO DI ECX
    call g              # int a = g();
    pushl %eax          # int c = a;
    call h              # int a = h()
    popl %ecx
    addl %ecx, %eax     # a = a + c;
    ret                 # return a;
