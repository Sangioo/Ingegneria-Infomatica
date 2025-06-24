void f(unsigned short n, unsigned short* spari, unsigned short* sdisp) {
    unsigned short c;
    *spari = 0;
    *sdisp = 0;
    for (c = 0; c <= n; c++) {
        if ((c & 1) == 0) *spari += c;
        else *sdisp += c;
    }
}