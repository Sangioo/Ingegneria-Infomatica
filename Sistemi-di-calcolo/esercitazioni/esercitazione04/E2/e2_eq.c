int find(int* v, int n, int x) {
    int* d = v;
    int c = n;
    int a = x;

G:
    if (c == 0) goto E;
    if (*d == a) goto F;
    d++;
    c--;
    goto G;
E:
    a = 0;
    return a;
F:
    a = 1;
    return a;
}
