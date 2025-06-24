#include <stdio.h>

unsigned f(unsigned x, unsigned y);

int main() {
    unsigned res = f(7,2);
    printf("res=%u\n", res);
    return 0;
}
