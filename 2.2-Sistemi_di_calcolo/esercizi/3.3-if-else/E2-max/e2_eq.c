int max(int x, int y) {
    int c = x;
    int d = y;
    int a;
    if (c<=d) goto F;
    a = c;
    goto E;
F:
    a = d;
E:
    return a;
}

