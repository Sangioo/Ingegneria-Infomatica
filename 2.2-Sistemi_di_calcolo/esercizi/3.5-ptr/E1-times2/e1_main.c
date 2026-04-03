#include <stdio.h>

void times2(short*);

int main() {
    short x = 15;
    times2(&x);
    printf("x=%hd\n", x);
    return 0;
}
