#include "e1.h"

int binsearch(int *v, int n, int x) {
    int *si = v;
    int di = n;
    int d = x;
    int c = 0;
    int a = 0;
E:
    if (c >= di) goto F;
    int b = di;
    b += c;
    b >>= 1;
    if (*(si + b) == d) goto G;
    if (*(si + b) <= d) goto H;
    di = b;
    goto E;
H:
    c = b;
    c++;
    goto E;
G:
    a = 1;
F:
    return a;
}