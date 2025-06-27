#include <stdio.h>

unsigned my_strlen(const char* s);

int main() {
    printf("res=%d\n", my_strlen("one"));
    printf("res=%d\n", my_strlen("hello world"));
    printf("res=%d\n", my_strlen(""));
    return 0;
}
