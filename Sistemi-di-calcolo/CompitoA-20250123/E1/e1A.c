#include "e1A.h"

unsigned transform(unsigned * array, unsigned len, unsigned *out)
{
    int i;
    unsigned sum = 0;

    for (i = 0; i < len; i++) {
        if (sum > array[i]) {
            out[i] = average(sum, i + 1);
        }
        else {
            out[i] = array[i];
        }
        sum += array[i];
    }

    return sum;
}