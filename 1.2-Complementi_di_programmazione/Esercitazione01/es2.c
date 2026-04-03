// Si scriva un programma in linguaggio C per calcolare la media aritmetica di una serie di numeri inseriti da tastiera.
// L'introduzione di un valore particolare pari a "0" indica il termine del caricamento dei dati.
#include <stdio.h>

int main() {
    double media, somma = 0, x;
    int n = 0;

    printf("inserire num: ");
    scanf("%lf", &x);
    while (x != 0) {
        somma = somma + x;
        n++;
        printf("inserire num: ");
        scanf("%lf", &x);
    }

    media = somma / n;
    printf("media: %lf\n", media);

    return 0;
}