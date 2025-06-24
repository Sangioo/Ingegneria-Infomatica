#include "e1A.h"

unsigned adler32(unsigned char *data, unsigned len) {
    if (data == NULL || len == 0)
        return 0;

    unsigned a = 1, b = 0;
    unsigned k;
    get_adler_constant(&k);

    int i;
    for (i = 0; i < len; ++i) {
        a = (a + data[i]) % k;
        b = (b + a) % k;    // Usare istruzione DIV 
                            // e fare attenzione ai 
                            // suoi vincoli sui registri!
    }
    return (b << 16) | a;
}
