#include "e6.h"

int sum(int *v, int n) {
    int i, s = 0;
    for (i=0; i+2<n; i+=3) {
        s += v[i];
        s += v[i+1];
        s += v[i+2];
    }
    for (; i<n; ++i) s += v[i];
    return s;
}
