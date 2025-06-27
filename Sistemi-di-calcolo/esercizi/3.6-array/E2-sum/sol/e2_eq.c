short sum(short* v, int n) {
    short* c = v;
    int d = n;
    short a = 0;
    d--;
L:  if (d<0) goto E;
    a = a + c[d];
    d--;
    goto L;
E:  return a;
}
