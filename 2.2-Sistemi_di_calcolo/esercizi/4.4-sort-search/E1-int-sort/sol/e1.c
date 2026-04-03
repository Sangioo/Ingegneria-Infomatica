#include "../e1.h"
#include <stdlib.h>
#include <string.h>

int compar(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x-y;
}

void sort_ints(int ints[], size_t size){
    qsort(ints, size, sizeof(int), compar);
}
