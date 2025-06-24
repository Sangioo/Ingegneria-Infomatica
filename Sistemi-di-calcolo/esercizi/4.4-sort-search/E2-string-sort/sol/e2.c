#include "../e2.h"
#include <stdlib.h>
#include <string.h>

int compar(const void* a, const void* b) {
    const char* x = *(char**)a;
    const char* y = *(char**)b;
    return strcmp(x, y);
}

void sort_strings(char *strings[], size_t size){
    qsort(strings, size, sizeof(char*), compar);
}
