#include <stdio.h>

int main() {
    unsigned x = 0xDEADBEEF;
    unsigned char y;
    for (int i = 0; i < 4; i++) {
        y = *((unsigned char *)&x + i);
        printf("%X\n", y);
    }
    return 0;
}
