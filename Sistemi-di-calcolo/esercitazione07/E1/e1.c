#include "e1.h"

int binsearch(int *v, int n, int x) {
    int i=0, j=n;
    while (i<j) {
        int m = (i+j)/2;
        if (v[m]==x) return 1;
        if (v[m]>x) j=m;
        else i=m+1;
    }
    return 0;
}