/*
Implementare la funzione

  int cammino_pari(TipoAlbero a)

che dato un albero a di interi, ritorni la somma degli elementi del cammino (percorso dalla radice ad una foglia) composto dal maggior numero di nodi contenenti un valore pari, a parità di tale condizione, restituire la somma maggiore.
Per l'albero vuoto restituire 0. Si noti che, se l’albero non ha nodi contenenti un valore pari, tutti i cammini hanno lo stesso numero di nodi contenenti un valore pari (ovvero 0), quindi la funzione deve restituire la somma maggiore tra le somme degli elementi di ogni cammino.

NB: Non è consentito accedere ai campi della struttura direttamente. E’ necessario usare l’interfaccia del tipo albero in aux.h
Esempio

Dato l'albero:

          2             
         / \
        3   2
       / \   \
      7   6   2
     /
    8

Il percorso con il maggior numero di nodi contenenti valori pari è 2 - 2 - 2

Output:
(2)+(2)+(2) = 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int cammino_aux(TipoAlbero a, int *n) {
	if (estVuoto(a)) {
    	*n = 0;
      	return 0;
    }
  	int n_sx = 0, n_dx = 0;
  	int sum_sx = cammino_aux(sinistro(a), &n_sx);
  	int sum_dx = cammino_aux(destro(a), &n_dx);
  	
  	*n += (radice(a) % 2 == 0) ? 1 : 0;
  	int sum = radice(a);
  	if (n_sx > n_dx) {
    	sum += sum_sx;
      	*n += n_sx;
    } else if (n_sx < n_dx) {
      	sum += sum_dx;
      	*n += n_dx;
    } else {
      	if (sum_sx >= sum_dx) {
          	sum += sum_sx;
          	*n += n_sx;
        } else {
          	sum += sum_dx;
          	*n += n_dx;
        }
    }
  	return sum;
}

int cammino_pari(TipoAlbero a) {
  	int n = 0;
  	return cammino_aux(a, &n);
}