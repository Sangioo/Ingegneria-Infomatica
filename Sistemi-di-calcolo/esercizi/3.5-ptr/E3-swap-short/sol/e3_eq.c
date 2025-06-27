void swap(short* x, short* y) {
    short* ecx = x;
    short* edx = y;
    short cx = *ecx;
    short dx = *edx;
    short* eax = x;
    *eax = dx;
    eax = y;
    *eax = cx;
}
