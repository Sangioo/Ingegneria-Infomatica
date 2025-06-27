int is_negative(int x);

int is_negative2(char x);

unsigned f(int *v, unsigned n) {
    unsigned i, cnt = 0;
    for (i = 0; i<n; ++i)
        cnt += is_negative2((char)v[i]);
    return cnt;
}

