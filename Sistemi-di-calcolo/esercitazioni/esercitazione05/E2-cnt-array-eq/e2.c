int counteq(short* v1, short* v2, int n) {
    int i, cnt = 0;
    for (i=0; i<n; ++i) cnt += (v1[i]==v2[i]);
    return cnt;
}