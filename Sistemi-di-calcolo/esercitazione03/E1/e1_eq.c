int min(int x, int y, int z) {
    int a = x;
    int c = y;
    int d = z;

    if (a >= c)
        goto E;
    // a < c
    if (a >= d)
        goto G;
    // a < d && a < c
    goto F;

G:
    // d <= a && a < c
    a = d;
    goto F;

// else
E:
    // c <= a
    if (c >= d)
        goto G;
    // c < d && c <= a
    a = c;
    goto F;

F:
    return a;
}
