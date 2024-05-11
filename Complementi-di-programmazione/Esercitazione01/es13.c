// Scrivere un programma che per dato in input un numero positivo intero R disegni un cerchio di
// asterischi di raggio R (nota: l'output sarà una forma ovale poiché le dimensioni dei pixel non sono quadrate).
#include <stdio.h>

int main() {
    int r, res;

    scanf("%d", &r);
    for (int i=-r; i<=r; i++) {
        for (int j=-r; j<=r; j++) {
            res = i*i + j*j - r*r;
            if (res <= 0) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}