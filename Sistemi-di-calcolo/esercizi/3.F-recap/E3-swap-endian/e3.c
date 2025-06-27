#include "e3.h"

unsigned swap_endianness(unsigned c) {
    return  ((c & 0x000000FF)<<24) | ((c & 0x0000FF00)<<8) |
            ((c & 0x00FF0000)>>8)  | ((c & 0xFF000000)>>24);
}
