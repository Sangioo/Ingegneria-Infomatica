#include "../e3.h"
#include <stdlib.h>

int compar(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int search_int(int ints[], size_t size, int key) {
    void* res = bsearch(&key, ints, size, sizeof(int), compar);
    return res != NULL;
}
