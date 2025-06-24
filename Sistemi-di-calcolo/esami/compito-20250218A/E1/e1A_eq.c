#include "e1A.h"

int count_tokens(char* str, const char* sep) {
    char* di = str;
    const char* si = sep;
    int b = 0;
    char* a = strtok(di, si);
L:
    if (a == NULL)
        goto E;
    b++;
    a = strtok(NULL, si);
    goto L;
E:
    int eax = b;
    return eax;
}