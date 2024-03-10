// Scrivere un programma in linguaggio C che calcoli e stampi i primi N numeri della serie di Fibonacci,
// con N inserito da tastiera. La serie di Fibonacci inizia con 1, 1 ed ogni numero successivo
// è dato dalla somma dei due precedenti: 1, 1, 2, 3, 5, 8, 13, 21 . . .
// (si veda https://it.wikipedia.org/wiki/Successione_di_Fibonacci per maggiori dettagli)
#include <stdio.h>

int main() {
    int n, curr = 1, prev = 1, tmp;

    printf("inserire n: ");
    scanf("%d", &n);

    printf("1 ");
    for (int i=0; i<n; i++) {
        printf("%d ", curr);
        tmp = curr;
        curr = curr + prev;
        prev = tmp;
    }

    return 0;
}