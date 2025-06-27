#include "e6.h"

int sum(int *v, int n) {
    int i, s = 0;
    for (i=0; i<n; ++i) s += v[i];
    return s;
}
