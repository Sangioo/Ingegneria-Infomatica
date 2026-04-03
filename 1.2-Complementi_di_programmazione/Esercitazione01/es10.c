// Scrivere un programma in linguaggio C per la rappresentazione del triangolo di Floyd.
// Il triangolo di Floyd è un triangolo rettangolo che contiene numeri naturali,
// definito riempiendo le righe del triangolo con numeri consecutivi e partendo da 1 nell'angolo in alto a sinistra.
// Il programma deve ricevere da tastiera un numero intero N>0 e visualizzare le prime N righe del triangolo di Floyd.
#include <stdio.h>
#include <math.h>

int main() {
    int n, x = 1;

    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            printf("%d ", x);
            x++;
        }
        printf("\n");
    }

    return 0;
}