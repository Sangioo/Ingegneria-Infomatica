#include "e1.h"
#include <stdlib.h>

int compare(const void* p1, const void* p2) {
    return *(int *)p1 > *(int *)p2;
}

void sort_ints(int ints[], size_t size) {
    qsort(ints, size, sizeof(int), compare);
}