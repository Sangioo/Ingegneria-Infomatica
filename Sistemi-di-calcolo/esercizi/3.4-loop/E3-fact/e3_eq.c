unsigned fact(unsigned n) {
    unsigned a = 1, c;
    c = 2;
L:
    if (c > n) goto E;
    a *= c;
    ++c;
    goto L;
E:
    return a;
}
