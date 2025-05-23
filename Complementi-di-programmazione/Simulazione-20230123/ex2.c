/*
Regole
Nell'esercizio 2.1, non usare gli array
In entrambi 2.1 e 2.2, accedere alla struttura solo tramite l'interfaccia della lista fornita (ad esempio, non è consentito accedere a next e info). I metodi dell'interfaccia lista validi sono tutti quelli presenti nel file aux.h.
Ogni metodo in aux.h può essere utilizzato.
Esercizio 2.1

Si implementi la funzione ricorsiva:

  TipoLista minimiLocali(TipoLista l)

la quale riceve una lista di interi l. La funzione deve restituire una nuova lista contenente i minimi locali della lista l nell'ordine con cui appaiono in l. Una lista vuota non ha minimi locali.

NB: un elemento della lista l è minimo locale di l se:
 1) non è il primo o l’ultimo elemento di l
 2) è minore o uguale all’elemento che lo precede e a quello che lo segue
Esempio 1

l: [1,2,1,3,2,2,2]

Il terzo elemento della lista (1), il quinto elemento della lista (2) e il sesto elemento della lista (2) sono minimi locali

output: [1,2,2]
  

Esempio 2

l: [1,2,1,3]

Il terzo elemento della lista (1) è minimo locale

output: [1]
  

Esempio 3

l: [1,2,3,4,5]

La lista non ha minimi locali

output: []
  

Esercizio 2.2

Scrivere una funzione:

  int massimaSommaMinimi(TipoLista* liste, int n);

la quale riceve un array di n liste di interi. La funzione deve ritornare il massimo tra le somme dei minimi locali di ogni lista. Se l’array di liste è vuoto (ovvero n=0) la funzione deve ritornare 0.

NB: -se una lista non ha minimi locali, la somma dei suoi minimi locali è 0.
Esempio

liste: [
  [5,1,3,1,2]		minimi locali sono [1,1] e la loro somma è 2
  [1,7,0,2]		minimi locali sono [0] e la loro somma è 0
  [2,1,7,3,4,1]		minimi locali sono [1,3] e la loro somma è 4
  [8,4,4,4]		minimi locali sono [4,4] e la loro somma è 8
  []			non ci sono minimi locali, quindi la loro somma è 0

]


output: 8 (8 è il massimo tra 2, 0, 4, 8 e 0)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista minimiAux(TipoLista l, T e) {
	if (estVuota(cdr(l)))
      	return listaVuota();
  
  	if (car(l) <= e && car(l) <= car(cdr(l)))
      	return cons(car(l), minimiAux(cdr(l), car(l)));
 	
  	return minimiAux(cdr(l), car(l));
}

TipoLista minimiLocali(TipoLista l) {
	return minimiAux(cdr(l), car(l));
}

int sommaLista(TipoLista l) {
	if (estVuota(l))
      	return 0;
  	
  	return car(l) + sommaLista(cdr(l));
}

int massimaSommaMinimi(TipoLista* liste, int n) {
	if (n == 0) return 0;
  
  	int max = sommaLista(minimiLocali(liste[0]));
  	for (int i=1; i<n; i++) {
    	TipoLista l = minimiLocali(liste[i]);
      	int sum = sommaLista(l);
      	if (sum > max)
          	max = sum;
    }
  	return max;
}
