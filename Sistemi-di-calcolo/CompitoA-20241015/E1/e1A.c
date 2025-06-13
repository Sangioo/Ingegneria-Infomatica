#include "e1A.h"

char* cond_compute(char* array, unsigned* cond, int n, char* out)
{
    int i = 0;
    char res;

    for (i = 0; i < n; i++) {
        out[i] = array[i];
        if (cond[i]) {
            compute(out[i], &res);
            out[i] = res;
        }
    }

    return out;
}