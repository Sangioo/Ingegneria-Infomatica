void swap(short* x, short* y) {
    short* a = x;
    short ax = *a;
    short* c = y;
    short cx = *c;
    short* d = x;
    *d = cx;
    d = y;
    *d = ax;
}