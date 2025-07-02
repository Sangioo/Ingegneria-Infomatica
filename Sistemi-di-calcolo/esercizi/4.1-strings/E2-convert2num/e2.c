// Inserisci soluzione qui...

#include "e2.h"
#include <stdlib.h> // atoi

void f(char* in[], int out[], int n) {
    for (int i = 0; i < n; i++) {
        out[i] = atoi(in[i]);
    }
}
