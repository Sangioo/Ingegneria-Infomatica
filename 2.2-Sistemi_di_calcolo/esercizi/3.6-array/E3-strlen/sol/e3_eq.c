unsigned my_strlen(const char* s) {
    const char* c = s;
    unsigned a = 0;
L:  char d = *c;
    c++;
    if (d==0) goto E;
    a++;
    goto L;
E:  return a;
}
