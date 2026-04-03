#include "e1C.h"

int hextodec_sum(unsigned char *in, int *out)
{
    int sum = 0;
    unsigned i = 0;
    int res;

    while (*in) {
        hextodec_helper(in, &res);

        if (res > 0) {
            sum += res;
        }

        out[i++] = res;
        in += 2;
    }

    return sum;
}