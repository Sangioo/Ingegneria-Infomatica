int between(int x, int y, int z) {
    int a = x;
    int c = y;
    int d = z;
    if (a > c) goto F;
    if (c > d) goto F2;
    return 1;
F:
F2:
    return 0;
}
