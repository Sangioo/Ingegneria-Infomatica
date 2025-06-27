char* my_strcat(char* dest, const char* src) {
    char* d = dest;
    const char* c = src;
L:  if (*d==0) goto E;
    d++;
    goto L;
E:; char al = *c;
    *d = al;
    if (al==0) goto F;
    d++;
    c++;
    goto E;
F:; char* a = dest;
    return a;
}
