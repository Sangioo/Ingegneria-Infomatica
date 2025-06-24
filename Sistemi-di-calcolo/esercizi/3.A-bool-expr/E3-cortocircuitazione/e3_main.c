#include <stdio.h>

int stringa_vuota(const char *s);

int main() {
    printf("res=%d\n", stringa_vuota(NULL));
    printf("res=%d\n", stringa_vuota("hello world"));
    printf("res=%d\n", stringa_vuota(""));
    return 0;
}
