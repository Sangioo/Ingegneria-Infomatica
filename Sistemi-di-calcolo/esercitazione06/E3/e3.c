#include "e3.h"
#include <stdio.h>

// La funzione my_strpbrk(s1, s2) deve restituire il puntatore alla prima 
// occorrenza in `s1` di un qualsiasi carattere presente nella stringa `s2` 
// oppure `NULL` se alcun carattere di s2 appare in `s1` prima che `s1` 
// stessa termini.

char *my_strpbrk(const char *s1, const char *s2) {
    while (*s1) {
        char* ss2 = s2;
        while (*ss2) {
            if (*s1 == *ss2) return s1;
            ss2++;
        }
        s1++;
    }
    return 0;
}