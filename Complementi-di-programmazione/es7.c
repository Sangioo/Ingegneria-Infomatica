// Scrivere un programma che dati in input due numeri interi positivi N ed M (M sottomultiplo di N),
// disegni una scacchiera N*M x N*M con blocchi di asterischi M*M. 
#include <stdio.h>

int main() {
    double x, min;

    printf("inserire num: ");
    scanf("%lf", &x);
    min = x;

    while(x != 0) {
        if (x < min) {
            min = x;
        }
        printf("inserire num: ");
        scanf("%lf", &x);
    }

    printf("minimo: %lf", min);

    return 0;
}