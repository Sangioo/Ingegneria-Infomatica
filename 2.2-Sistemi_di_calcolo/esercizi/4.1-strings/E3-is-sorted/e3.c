// Inserisci soluzione qui...

#include <string.h>

int is_sorted(char *v[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (strcmp(v[i], v[i+1]) < 0) return 0;
    }
    return 1;
}


