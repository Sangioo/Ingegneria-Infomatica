#include "../e2.h"
#include <stdlib.h>

void f(char* in[], int out[], int n) {
    int i;
    for (i=0; i<n; ++i)
        out[i] = atoi(in[i]);
}
