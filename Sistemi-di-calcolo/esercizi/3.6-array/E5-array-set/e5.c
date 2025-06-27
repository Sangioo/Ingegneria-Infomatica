void array_set(short* v, int n, short x) {
    short* p = v + n - 1;
    while (p >= v) {
        *p-- = x;
    }
}
