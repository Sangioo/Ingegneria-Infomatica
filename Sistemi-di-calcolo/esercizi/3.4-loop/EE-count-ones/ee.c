unsigned count1(unsigned n) {
    unsigned a = 0; // counter
    while (n>0) {
        if (n & 1) a++;
        n = n >> 1; // oppure n/=2
    }
    return a;
}
