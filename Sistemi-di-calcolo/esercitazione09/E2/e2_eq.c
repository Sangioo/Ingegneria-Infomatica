#include "e2.h"

int crc32b(char *bytes, int n) {
    int ecx = n;
    int ebx = 0;
    ebx = ~ebx;
    int eax = ebx;
E:
    if (ecx <= 0) goto F;
    int value;
    int byte = *bytes;
    bytes++;
    int index = eax;
    index ^= byte;
    index &= 0xFF;
    get_constant(&value, index);
    eax = eax >> 8;
    eax ^= value;
    ecx--;
    goto E;
F:
    eax ^= ebx;
    return eax;
}