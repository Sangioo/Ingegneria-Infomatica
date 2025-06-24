#include "e1A.h"

int slice(char* str, int start, int end, char* res)
{
    int i = 0;
    int size = end - start - 1;

    while (*str != '\0') {
        if (i++ == start) {
            slice_helper(str, size, res);
        }
        str++;
    }

    if (i < start) {
        size = 0;
    }
    return size;
}