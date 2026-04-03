// Si realizzi un programma in linguaggio C che legga un numero x e restituisca la sua radice quadrata calcolata secondo il metodo di Newton
// (si veda https://it.wikipedia.org/wiki/Metodi_per_il_calcolo_della_radice_quadrata#Radici_quadrate_usando_il_metodo_iterativo_di_Newton).

#include <stdio.h>

int main() {
    double x, r;
    int n = 5;

    scanf("%lf", &x);

    r = x;

    for (int i=0; i<n; i++) {
        r = (r + x/r) / 2;
    }

    printf("%lf", r);

    return 0;
}