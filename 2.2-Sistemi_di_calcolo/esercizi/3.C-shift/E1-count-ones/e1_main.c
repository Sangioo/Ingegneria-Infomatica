#include <stdio.h>

unsigned count1(unsigned n);

int main() {
    unsigned res = count1(0xE0E0E0E0);
    printf("res=%d\n",res);
    return 0;
}
