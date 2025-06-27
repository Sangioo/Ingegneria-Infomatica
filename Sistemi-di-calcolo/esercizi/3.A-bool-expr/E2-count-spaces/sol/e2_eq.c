int count_spaces(const char* s) {
    const char *c = s;
    int a = 0;
    char dl;
L:  dl = *c;
    if (dl == 0) goto E;
    dl = dl == 32;
    int d = dl;
    a += d;
    c++;
    goto L;
E:  return a;
}
