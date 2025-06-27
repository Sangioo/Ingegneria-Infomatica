#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e2.h"

// la funzione bubblesort deve ordinare un array di nel stringhe 
// della stessa lunghezza size usando l'algoritmo bubblesort che
// fa passate multiple sull'array confrontando stringhe
// consecutive, scambiandole di posto se non sono in ordine
// lessicografico

int main() {

    char buf[] = "uno  due  tre  quat cinq sei  sett otto nove diec ";
    printf("Prima dell'ordinamento: %s\n", buf);
    bubblesort(buf, 10, 5);
    printf("Dopo l'ordinamento:     %s\n", buf);
    return 0;
}
