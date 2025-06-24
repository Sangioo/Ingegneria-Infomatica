#include "e2.h"

#define STRIDE 64

long f(const short *v, unsigned n){
    long x = 0;
    unsigned i, j;
    for (i=0; i<STRIDE; ++i)
        for (j=0; j<n; j+=STRIDE) x += v[i+j];
    return x;
}
