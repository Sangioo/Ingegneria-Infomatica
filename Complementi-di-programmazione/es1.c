// Data l'equazione:
// a x + b = 0 
// con a e b inseriti da tastiera, scrivere un programma in linguaggio C per determinare il valore di x,
// se esiste, che risolve l'equazione.

#include <stdio.h>

int main() {
    double a, b;
    double x;

    printf("inserire a: ");
    scanf("%lf", &a);
    printf("inserire b: ");
    scanf("%lf", &b);

    if (a != 0) {
        printf("\nax + b = 0 <=> x = %lf", -b/a);
    } else {
        printf("\nimpossibile eseguire\n");
    }


    return 0;
}