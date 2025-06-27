#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../e5.h"

char* strextstrd(const char *S, int STRIDE) {

    const char* si = S;
    int di = STRIDE;

    // Callee-save:
    // si=S, di=STRIDE, bp=n, b=0

    int bp = strlen(si);
    int EDXEAX = bp;
    int a1 = EDXEAX / di;
    a1++;
    char* a = malloc(a1);
    char* b = a;
    if (a == NULL) goto E;
    int c = 0;
L:  if (c>=bp) goto F;
    char d = si[c];
    *b = d;
    b++;
    c += di;
    goto L;
F:  *b = 0;
E:  return a;
}
