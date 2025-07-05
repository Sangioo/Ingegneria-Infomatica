#include "e1A.h"

char* str_to_upper(const char* s) {
    if (s == NULL) return NULL;
    // strdup e' una funzione della libreria C!
    char* s_copy = strdup(s);
    char* copy = s_copy;
    while (*copy) {
        // toupper e' una funzione della libreria C!
        char c = toupper(*copy); 
        *copy = c;
        copy++;
    }
    return s_copy;
}
