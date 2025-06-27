#include <stdio.h>

int between(short x, short y, short z);

int main() {
    int res = between(-21, 0, 40);
    printf("%d\n", res); // deve stampare 1
    res = between(-21, -22, 40);
    printf("%d\n", res); // deve stampare 0
    res = between(-21, 50, 40);
    printf("%d\n", res); // deve stampare 0
    return 0;
}
