#include "e4.h"

int lcm(int x, int y) {
    int greater = y;
    if (x > y)
        greater = x;
    while (1) {
        if ((greater % x == 0) && (greater % y == 0))
            return greater;
        greater++;
    }
}
