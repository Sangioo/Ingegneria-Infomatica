// Scrivi il C equivalente qui...

#include <stdlib.h>

int stringa_vuota(const char *s) {
    const char *c = s;
/*  versione errata senza cortocircuitazione
    char al = c == 0;   // assunzione: NULL vale 0
    char ah = *c == 0;  // terminatore di stringa
    al = al & ah;
    int a = al;
*/
    int a = 0;
    if (c == 0) // cortocircuitazione
        goto E;
    if (*c != 0) 
        goto E;
    a = 1;
E:  return a;  
}
