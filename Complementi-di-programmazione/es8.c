// Scrivere un programma in linguaggio C che legge una serie di valori interi positivi in input e ne restituisce il minimo.
// La sequenza di inserimento termina quando viene inserito il valore 0, che non deve essere conteggiato nel calcolo del minimo.
#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    while(x != 0) {
        for (int i=0; i<x; i++) {
            printf("*");
        }
        printf("\n");

        scanf("%d", &x);
    }

    return 0;
}