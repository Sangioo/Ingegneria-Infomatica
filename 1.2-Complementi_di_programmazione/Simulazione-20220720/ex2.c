#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int len(TipoLista l) {
  	if (estVuota(l)) return 0;
  	return 1 + len(cdr(l));
}

int pos_aux(TipoLista l, T e0, T e1, int i) {
  	if (estVuota(l)) {
      	return 0;
    }
  	if (i == 0 && car(l) == e0) {
   		return 1 + pos_aux(cdr(l), e0, e1, (i+1)%2);
    }
  	if (i == 1 && car(l) == e1) {
      	return 1 + pos_aux(cdr(l), e0, e1, (i+1)%2);
    }
  	return 0;
}

int posizioni_alternanza(TipoLista l) {
  	if (estVuota(l)) return 0;
  	if (len(l) == 1) return 1;
  	if (len(l) == 2) return 2;
  	return pos_aux(l, car(l), car(cdr(l)), 0);
}

char * prefisso_alternante(TipoLista *liste, int n) {
  	int maxp = posizioni_alternanza(liste[0]);
  	int maxi = 0;
  	for (int i=1; i<n; i++) {
      	int prefix = posizioni_alternanza(liste[i]);
      	if (prefix > maxp) {
            maxp = prefix;
            maxi = i;
        }
    }
  	int lung = len(liste[maxi]) - maxp + 1;
  	char *stringa = (char *) malloc(sizeof(char)*lung);
  	
  	int i = 0;
  	TipoLista l = liste[maxi];
  	while (!estVuota(l)) {
      	if (i-maxp >= 0)
          	stringa[i-maxp] = car(l);
      	l = cdr(l);
      	i++;
    }
	
  	return stringa;
}
