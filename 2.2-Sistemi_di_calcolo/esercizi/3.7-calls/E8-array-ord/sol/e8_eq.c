int ordinati(int x, int y);

unsigned f(int *v, unsigned n) {
    unsigned b;
    int* di = v;
    unsigned si = n;
    b = 1;
L1: if (b>=si) goto L2;
    int c = di[b-1];
    int d = di[b];
    int a = ordinati(c,d);
    if (a == 0) goto L3;
    b++;
    goto L1;
L3: a = 0;
    goto E;
L2: a = 1;
E:  return a;
}

