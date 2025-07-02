#include "e2.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void bubblesort(void* buf, size_t nel, size_t size) {
    void* tmp = malloc(size);
    assert(tmp != NULL);

    for (int i = 0; i < nel - 1; i++) {
        for (int j = 0; j < nel - i - 1; j++) {
            if (memcmp(buf + j*size, buf + (j + 1)*size, size) > 0) {
                memcpy(tmp, buf + (j + 1)*size, size);
                memcpy(buf + (j + 1)*size, buf + j*size, size);
                memcpy(buf + j*size, tmp, size);
            }
        }
    }
}