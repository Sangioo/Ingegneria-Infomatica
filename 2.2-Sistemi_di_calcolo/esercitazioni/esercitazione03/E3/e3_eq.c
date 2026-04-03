int comp(const void* xv, const void* yv) {
    int* c = (int*)xv;
    int* d = (int*)yv;
    int a = *c - *d;
    return a;
}
