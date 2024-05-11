// Si scriva un programma in linguaggio C per calcolare il minimo comune multiplo (mcm) di
// due numeri interi positivi. Dati due numeri interi N1 e N2, il minimo comune multiplo è
// il più piccolo numero M che è divisibile (con resto pari a zero) sia per N1 che per N2.
// Per maggiori informazioni si veda https://it.wikipedia.org/wiki/Minimo_comune_multiplo
#include <stdio.h>

int main() {
    int n1, n2, mcm;

    scanf("%d %d", &n1, &n2);

    if (n1 > n2) {
        for (int i = n1+1; i <= n1*n2; i++) {
            if (i%n1 == 0 && i%n2 == 0) {
                mcm = i;
            }
        }
    } else {
        for (int i = n2+1; i <= n1*n2; i++) {
            if (i%n1 == 0 && i%n2 == 0) {
                mcm = i;
            }
        }
    }

    printf("%d", mcm);

    return 0;
}