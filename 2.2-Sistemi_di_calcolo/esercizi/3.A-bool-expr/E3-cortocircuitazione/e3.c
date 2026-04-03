#include <stdlib.h>

int stringa_vuota(const char *s) {
    return s != NULL && *s == 0;  // assunzione: NULL vale 0
}
