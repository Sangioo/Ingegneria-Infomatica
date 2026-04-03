#include <stdio.h>

int count_spaces(const char* s);

int main() {
    printf("res=%d\n", count_spaces("one world"));
    printf("res=%d\n", count_spaces("hello world  "));
    printf("res=%d\n", count_spaces("burger"));
    return 0;
}
