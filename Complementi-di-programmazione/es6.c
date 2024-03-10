#include <stdio.h>

int main() {
    int n, m, lato;

    printf("inserire N e M: ");
    scanf("%d %d", &n, &m);

    lato = n*m;
    printf("%d %d %d\n", n, m, lato);


    for (int i=0; i<lato; i++) {
        for (int j=0; j<lato; j++) {
            if ((i%(2*m) < m && j%(2*m) < m) || (i%(2*m) >= m && j%(2*m) >= m)) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}