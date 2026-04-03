#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e5.h"

char* strextstrd(const char *s, int stride) {
    int n = strlen(s);
    char* a = malloc(n/stride+1);
    char* b = a;
    if (a == NULL) return NULL;
    int i;
    for (i=0; i<n; i+=stride) {
        *a++ = s[i];
    }
    *a = 0;
    return b;
}
