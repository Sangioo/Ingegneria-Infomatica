int is_negative(int x);

unsigned f(int *v, unsigned n) {
    int* di = v;       // di <-> v
    unsigned si = n;   // si <-> n
    unsigned b = 0;    // b <-> i
    unsigned bp = 0;   // bp <-> cnt
L:  if (b >= si)
        goto E;
    int c = v[b];
    unsigned a = is_negative(c);
    bp = bp + a;
    b++;
    goto L;
E:  a = bp;
    return a;
}

