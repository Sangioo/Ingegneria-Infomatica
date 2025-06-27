void prod(short x, char y, int * res);

int check(short* a, char* b, unsigned n) {
    short* esi = a;
    short* ebx = esi;
    unsigned ecx = n;
    char* edi = b;
    int res;

    ebx = ebx + ecx;
    ebx = ebx - 1;
L:
    if (ebx < esi) goto E;
    prod(*ebx, *edi, &res);
    if (res != 6) goto F;
    return 1;
F:
    ebx--;
    edi++;
    goto L;
E:
    return 0;
}
