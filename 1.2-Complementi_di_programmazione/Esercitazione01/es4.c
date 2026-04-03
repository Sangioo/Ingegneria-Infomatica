// Si realizzi una variante del programma precedente per visualizzare solo i lati del quadrato (vedi esempio con N = 5).
#include <stdio.h>

int main() {
    int n;

    printf("inserire N: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==0 || j==0 || i==n-1 || j==n-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}