unsigned fact(unsigned n) {
    unsigned a = 1, c;
    for (c = 2; c <= n; ++c)
        a *= c;
    return a;
}
