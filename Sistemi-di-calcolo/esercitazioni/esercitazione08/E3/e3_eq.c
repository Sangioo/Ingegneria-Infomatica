int count_digits(const char *s) {
    int a = 0;
    char *c = s;
E:
    if (*c == '\0') goto F;

    if (*c < 48) goto G;
    if (*c > 57) goto G;
    a++;
G:
    c++;
    goto E;
F:
    return a;
}