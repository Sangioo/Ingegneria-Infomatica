int ordinati(int x, int y);

unsigned f(int *v, unsigned n) {
    unsigned i;
    for (i = 1; i<n; ++i)
        if (!ordinati(v[i-1],v[i])) return 0;
    return 1;
}
