#include "../e2.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void mem_swap(void* s1, void* s2, size_t n){
    void* tmp = malloc(n);
    assert(tmp != 0);
    memcpy(tmp, s1, n);
    memcpy(s1, s2, n);
    memcpy(s2, tmp, n);
    free(tmp);
}

void bubblesort(void* buf, size_t nel, size_t size) {
    char *v = buf;
    for (;;) {
        int i, swaps = 0;
        for (i=1; i<nel; ++i)
            if (memcmp(v+(i-1)*size, v+i*size, size) > 0) {
                mem_swap(v+(i-1)*size, v+i*size, size);
                swaps = 1;
             }
        if (!swaps) break;
    }
}
