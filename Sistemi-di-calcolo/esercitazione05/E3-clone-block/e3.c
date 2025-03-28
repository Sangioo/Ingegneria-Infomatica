#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n) {
    void* des = malloc(n);
    if (des==0) return 0;
    memcpy(des, src, n);
    return des;
}