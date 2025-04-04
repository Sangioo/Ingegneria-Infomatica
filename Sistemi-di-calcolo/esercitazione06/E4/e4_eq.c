#include "e4.h"

int lcm(int x, int y) {
    int si = x;
    int di = y;
    int c = di;
    if (si > di) c = si;
    int a;
E:
    a = c;
    int d = a % si;
    if (d != 0) goto F;
    a = c;
    d = a % di;
    if (d != 0) goto F;
    a = c;
    return a;
F:
    c++;
    goto E;
}