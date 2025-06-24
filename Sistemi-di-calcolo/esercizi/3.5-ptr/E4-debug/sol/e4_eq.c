void f(unsigned short n, unsigned short* spari, unsigned short* sdisp) {
    unsigned short c;
    unsigned a = n;
    unsigned short *d;
    d = spari;
    *d = 0;
    d = sdisp;
    *d = 0;
    c = 0;
L:  if (c > a) goto E;
    if ((c & 1) != 0) goto F;
    d = spari;
    *d += c;
    goto C;
F:
    d = sdisp;
    *d += c;
C:
    c += 1;
    goto L;
E:
    return;
}