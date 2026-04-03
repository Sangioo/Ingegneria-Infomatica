#include "e2.h"
#include <stdlib.h>
#include <string.h>

int compare(const void* p1, const void* p2) {
    return strcmp(*(char **)p1, *(char **)p2);
}

void sort_strings(char *strings[], size_t size) {
    qsort(strings, size, sizeof(char *), compare);
}