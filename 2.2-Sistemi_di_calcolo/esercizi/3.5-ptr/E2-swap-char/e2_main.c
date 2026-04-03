#include <stdio.h>

void swap(char* x, char* y);

int main() {
    char a = 'a';
    char b = 'b';
    swap(&a, &b);
    printf("a=%c - b=%c\n", a, b);
    return 0;
}
