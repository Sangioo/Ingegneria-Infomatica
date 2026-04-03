int between(int x, int y, int z) {
    int a = x, c = y, d = z;
    if (a>c) goto E;
    if (c>d) goto E;
    a = 1;
    return a;
E:  a = 0;
    return a;
}
