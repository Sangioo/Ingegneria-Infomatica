#include "e3.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

int most_freq_char(const char *buf, size_t nel) {
    int count[256] = { 0 }, i;
    for (i = 0; i < nel; i++) {
        count[buf[i]]++;
    }
    int max = 0;
    for (i = 1; i < 256; i++) {
        if (count[i] > count[max]) {
            max = i;
        }
    }
    return max;
}
