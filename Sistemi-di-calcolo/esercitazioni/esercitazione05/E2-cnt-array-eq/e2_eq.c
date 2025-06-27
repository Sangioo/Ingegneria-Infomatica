int counteq(short* v1, short* v2, int n) {
    int* di = v1;
    int* si = v2;
    int a = 0;
    int d = n;
    d--;
E:
    if (d < 0) goto F;
    short b = di[d];
    short c = si[d];
    if (b != c) goto G;
    a++;
G:
    d--;
    goto E;
F:
    return a;
}