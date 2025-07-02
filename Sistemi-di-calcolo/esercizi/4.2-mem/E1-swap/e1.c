#include "e1.h"
#include <assert.h> // assert
#include <stdlib.h> // malloc e free
#include <string.h> // memcpy

void mem_swap(void* s1, void* s2, size_t n) {
    void* tmp = malloc(n);
    assert(tmp != NULL);

    memcpy(tmp, s1, n);
    memcpy(s1, s2, n);
    memcpy(s2, tmp, n);

    free(tmp);
}

