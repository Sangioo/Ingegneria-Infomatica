#include "e1A.h"

short* cond_compute(short* array, unsigned* cond, int n, short* out)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        if (!cond[i]) 
            out[i] = array[i];
        else
            out[i] = compute(array[i]);
    }

    return out;
}