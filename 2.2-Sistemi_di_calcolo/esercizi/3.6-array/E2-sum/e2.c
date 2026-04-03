short sum(short* v, int n) {
    int i;
    short a = 0;
    for (i=0; i<n; i++)
        a = a + v[i];
    return a;
}

