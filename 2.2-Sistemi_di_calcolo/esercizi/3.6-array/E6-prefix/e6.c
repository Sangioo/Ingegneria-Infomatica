#include "e6.h"
#include <string.h>

int is_prefix(const char* s, const char* t) {
    while (*s && *t && *s == *t) { s++; t++; }
    return *s == 0 ? 1 : 0;
}