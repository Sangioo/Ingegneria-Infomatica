unsigned fact(unsigned n) {
    unsigned a, c, d;
    a = 1;
    d = n;
    c = 2;
L:  if (c > d) 
        goto E;
    a = a * c;
    c++;
    goto L;
E:  return a;
}
