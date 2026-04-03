#include <stdio.h>

unsigned count1(unsigned n);

int main() {
    unsigned res = count1(0xF0F0F0F0);
    printf("res=%d\n",res);
    return 0;
}
