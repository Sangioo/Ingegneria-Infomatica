// Si realizzi un programma in linguaggio C che legga un numero intero N
// e visualizzi un quadrato di asterischi di lato N (vedi esempio con N = 5).
#include <stdio.h>

int main() {
    int n;

    printf("inserire N: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}