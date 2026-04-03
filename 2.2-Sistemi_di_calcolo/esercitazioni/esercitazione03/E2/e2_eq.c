unsigned int fib(unsigned int n) {
    unsigned int c = n;
    unsigned int d = 0; //fib1
    unsigned int a = 1; //fib2

    if (c != 0) goto R1;
    a = d;
    return a;

R1:
    if (c != 1) goto FOR;
    return a;

FOR:
    if (c <= 1) goto END;

    d = d + a;
    d = d + a;
    a = -a;
    a = a + d;
    d = d - a;

    c--;
    goto FOR;

END:
    return a;
}
