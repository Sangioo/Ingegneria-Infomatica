#include "e1A.h"

unsigned char* deleetify(unsigned char* v, unsigned len)
{
    unsigned char* res = malloc(len * sizeof(unsigned char));
    unsigned i;

    for (i = 0; i < len; i++) {
        if (v[i] > 57)
            res[i] = v[i];
        else
            res[i] = deleetify_helper(v[i]);
    }
    return res;
}
