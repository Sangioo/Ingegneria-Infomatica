#include "../e1.h"

void div_mod(int X, int Y, int* Q, int* R) {
    int a = X;
    int *c, d;
    d = a % Y;
    a = a / Y;
    c = Q;          // write back
    *c = a;
    c = R;
    *c = d;
}
