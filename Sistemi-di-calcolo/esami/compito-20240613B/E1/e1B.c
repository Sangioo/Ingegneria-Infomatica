#include "e1B.h"

void deleetify(unsigned char* v, unsigned len, unsigned char* res)
{
    unsigned i;
    unsigned char chr;

    for (i = 0; i < len; i++) {
        if (v[i] > 57) {
            res[i] = v[i];
        }
        else {
            deleetify_helper(v[i], &chr);
            res[i] = chr;
        }
    }
}