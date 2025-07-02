#include "e3.h"
#include <stdlib.h>
#include <stdio.h>

int compare(const void* p1, const void* p2) {
    return *(int *)p1 - *(int *)p2;
}

int search_int(int ints[], size_t size, int key) {
    qsort(ints, size, sizeof(int), compare);

    return bsearch(&key, ints, size, sizeof(int), compare) != NULL;
}