#include "e2.h"

int mcd(int x, int y) {
    while (y!=0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}
