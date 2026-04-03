// Scrivere un programma che trovi il più piccolo numero straordinario.
// Il numero straordinario ha questa proprietà: è composto da una qualsiasi
// permutazione delle cifre 1, 2, 4, 5, 7, 8, e i suoi prodotti per
// 2, 3, 4, 5, 6 sono a loro volta composti dalle cifre 1, 2, 4, 5, 7, 8.
#include <stdio.h>

int main() {
    int min = 124578, max = 875421;
    int tmp, m, uno, due, quattro, cinque, sette, otto, male, conta;

    for (int i = min; i < max; i++) {
        tmp = i;
        conta = 0;
        for (int j=1; j<7; j++) {
            tmp = i*j;
            uno = 0;
            due = 0;
            quattro = 0;
            cinque = 0;
            sette = 0;
            otto = 0;
            male = 0;
            while (tmp != 0) {
                m = tmp % 10;
                switch(m) {
                    case 1:
                        uno++;
                        break;
                    case 2:
                        due++;
                        break;
                    case 4:
                        quattro++;
                        break;
                    case 5:
                        cinque++;
                        break;
                    case 7:
                        sette++;
                        break;
                    case 8:
                        otto++;
                        break;
                    default:
                        male++;
                        break;
                }
                tmp -= m;
                tmp /= 10;
            }
            if (male != 0 || uno != 1 || due != 1 || quattro != 1 || cinque != 1 || sette != 1 || otto != 1) {
                break;
            } else {
                conta++;
            }
        }
        if (conta == 6) {
            printf("%d", i);
        }
    }

    return 0;
}