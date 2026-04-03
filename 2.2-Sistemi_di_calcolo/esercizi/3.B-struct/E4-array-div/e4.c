#include "e4.h"

void array_div(const int *a, const int *b, div_rem_t *res, int n) {
    int i;
    for (i=0; i<n; ++i) {
        int min = a[i] <  b[i] ? a[i] : b[i];
        int max = a[i] >= b[i] ? a[i] : b[i];
        res[i].quot = max / min;
        res[i].rem  = max % min;
    }
}
