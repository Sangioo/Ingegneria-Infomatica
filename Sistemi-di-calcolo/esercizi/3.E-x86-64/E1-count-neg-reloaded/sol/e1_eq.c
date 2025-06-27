int is_negative(int x);

unsigned f(int *v, unsigned n) {
    int* r12 = v;       // r12 <-> v
    unsigned r13 = n;   // r13 <-> n
    unsigned r14 = 0;   // r14 <-> cnt
    unsigned b = 0;     // b <-> i
L:  if (b >= r13)
        goto E;
    int di = r12[b];
    unsigned a = is_negative(di);
    r14 = r14 + a;
    b++;
    goto L;
E:  a = r14;
    return a;
}

