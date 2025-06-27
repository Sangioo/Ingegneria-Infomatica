void get_div_rem(int *d, int *r, int x, int y);

int f(int x, int y) {
    int d, r;
    get_div_rem(&d, &r, x, y);
    return d;
}
