#include "../e2.h"

int mcd(int X, int Y) {
    int a = X;
    int c = Y;
L:  if (c==0) goto E;
    int b = c;
    int d = a % c;
    c = d;
    a = b;
    goto L;
E:  return a;
}
