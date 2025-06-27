int find(int* v, int n, int x) {
    int i;
    for (i=0; i<n; ++i)
        if (v[i] == x) return 1;
    return 0;
}
