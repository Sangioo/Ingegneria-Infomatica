#include "e5.h"

int f(int x, int y) {
    int b = x;
    int di = y;
    int a = g(b, di);
    int si = a;
    a = g(di, b);
    a = a + si;
    return a;
}