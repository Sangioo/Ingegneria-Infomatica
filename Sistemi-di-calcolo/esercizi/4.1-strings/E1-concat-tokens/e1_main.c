#include <stdio.h>
#include <stdlib.h>
#include "e1.h"

// la funzione deve eliminare tutti i caratteri ' ' e ',' 
// dalla stringa data in input, restituendo una nuova
// stringa con le caratteristiche date. La stringa data
// in input non deve essere modificata. La stringa
// restituita deve essere allocata dinamicamente.

int main() {
    char *s = "uno due tre quattro, cinque, sei";
    char *res = f(s);
    printf("Stringa originaria: %s\n", s);
    printf("Stringa ottenuta: %s\n", res);
    free(res);
    return 0;
}
