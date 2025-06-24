unsigned int fib(unsigned int n) {
    unsigned int fib1 = 0, fib2 = 1;
    if (n == 0)
        return fib1;
    if (n == 1)
        return fib2;
    for (; n > 1; n--) {
        fib1 = fib1 + fib2;
        // scambiamo fib1 e fib2 senza usare variabile aggiuntiva
        fib1 = fib1 + fib2;
        fib2 = fib1 - fib2; // ricorda che in IA32 le istruzioni sono "D = D op S" 
                            // mentre questa istruzione e' "D = S - D" pero' puo' essere 
                            // facilmente spezzata in due passaggi! 
        fib1 = fib1 - fib2;
    }
    return fib2;
}