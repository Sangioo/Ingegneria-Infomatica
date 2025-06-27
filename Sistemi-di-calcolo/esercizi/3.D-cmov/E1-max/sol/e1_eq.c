#include "../e1.h"

int max(int X, int Y) {
    int a = X;
    int c = Y;
    if (c <= a) goto E;
    a = c;
E:  return a;
}
