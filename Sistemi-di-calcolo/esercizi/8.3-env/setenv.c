#include <stdlib.h>
#include <stdio.h>

int main() {
    int r = setenv("PATH", "pippo", 1);
    printf("r: %d\n", r);
    char* s = getenv("PATH");
    if (s) {
        printf("PATH=%s\n", s);
    }
    return 0;
}