#include "../e6.h"

int is_prefix(const char* s, const char* t) {
    const char *c = s;
    const char *d = t;
L:; char a = *c;
    if (a == 0)
        goto E;
    if (*d == 0)
        goto E;
    if (a != *d)
        goto E;
    c++;
    d++;
    goto L;
E:
    int ret = 0;
    if (a != 0) goto E2;
    ret = 1;
E2:
    return ret;
}