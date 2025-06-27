int is_negative(int x);

unsigned f(int *v, unsigned n) {
    unsigned i, cnt = 0;
    for (i = 0; i<n; ++i)
        cnt += is_negative(v[i]);
    return cnt;
}

