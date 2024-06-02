## domanda
Scrivere una funzione ricorsiva a piacere (input: un intero, output: un intero) che usi un passaggio di parametro per valore, una porzione di codice che invoca tale funzione, il risultato dell'esecuzione della chiamata e una descrizione dell'esecuzione run-time della funzione mettendo in evidenza la memoria usata nel passaggio di parametro per valore.

## risposta
La seguente funzione calcola la potenza di 2 corrispondente all'intero inserito (input: 3, output: 8)
```c
#include <stdio.h>
#include <stdlib.h>

int potenza(int i) {
    if (i == 0) {
        return 1;
    } else {
        return 2 * potenza(i-1);
    }
}

int main() {
    int in = 3;
    int out = potenza(in);
    printf("2^%d: %d\n", in, out);
}
```
Alla prima chiamata della funzione viene passato il valore di in ovvero 3, di conseguenza viene attivato il record di attivazione della funzione, allocando lo spazio per valore di ritorno, parametro e per il codice della funzione, poi viene messo all'interno della zona di memoria del parametro il valore 3, dato che il valore del parametro è diverso da 0 entriamo nell'else e dunque chiamiamo ricorsivamente la funzione stessa decrementando il parametro.

Viene così chiamata la funzione potenza con parametro 2, viene attivato il record di attivazione e inserito nella memoria allocata per il parametro il valore 2, il parametro ancora non è uguale a 0 dunque richiamiamo la funzione con valore ancora decrementato.

Viene attivato un altro record di attivazione della funzione, inserendo nella memoria allocata per il parametro il valore 1, ancora il parametro non è uguale a 0, dunque chiamiamo per l'ultima volta la funzione ricorsivamente.

Viene attivato l'ultimo record di attivazione con parametro 0, essendo il parametro 0 la condizione dell'if è verificata e viene inserito nell'area allocata per il valore di ritorno il valore 1.

A questo punto il record di attivazione precedente, quello con parametro 1, riceve il valore di ritorno e può eseguire l'operazione di prodotto 2 * 1, e ritornare a sua volta il valore 2.

Dunque il record di attivazione con parametro 2, riceve il valore e lo moltiplica per 2, ritornand il valore 4.

Arriviamo al record di attivazione che per primo è stato allocato, riceve il valore 4 e lo moltiplica per 2, ritornando il valore 8.

In fine il main riceve il valore ritornato dalla funzione e lo assegna alla variabile out, che viene poi stampata a schermo.