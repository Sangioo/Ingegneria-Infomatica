// Si scriva un programma in linguaggio C che converta un numero binario in un numero decimale.
// Il numero binario è rappresentato su N bit, e il valore di N è inserito da tastiera.
// L'utente inserisce le cifre del numero binario un bit alla volta, partendo dal bit meno significativo (ossia dal bit di peso }).
// Il programma visualizzerà il numero decimale corrispondente.
#include <stdio.h>
#include <math.h>

int main() {
    int bit, n, num = 0;

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &bit);
        num = num + (int) bit*pow(2,i);
    }

    printf("%d", num);

    return 0;
}