#include "../e3.h"

unsigned swap_endianness(unsigned C) {
    unsigned a = C, c = C, d = C;
    a = a & 0x000000FF;
    a = a << 24;
    c = c & 0x0000FF00;
    c = c << 8;
    a = a | c;
    c = d;
    c = c & 0x00FF0000;
    c = c >> 8;
    a = a | c;
    c = d;
    c = c & 0xFF000000;
    c = c >> 24;
    a = a | c;
    return a;
}
