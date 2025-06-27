#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e1.h"

// la funzione mem_swap deve scambiare il contenuto di due
// buffer di memoria ciascuno contenente n byte

int main() {
    char s1[] = "Where eagles dare...";
    char s2[] = "Another one bites...";
    printf("Buffer originari: s1=\"%s\" | s2=\"%s\"\n", s1, s2);
    mem_swap(s1, s2, strlen(s1)+1);
    printf("Buffer ottenuti:  s1=\"%s\" | s2=\"%s\"\n", s1, s2);
    return 0;
}
