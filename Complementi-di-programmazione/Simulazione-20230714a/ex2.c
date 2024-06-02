#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista suffisso(TipoLista l, bool *check) {
  	if (estVuota(l))
      	return listaVuota();
  	
	if (estVuota(cdr(l)))
      	return cons(car(l), listaVuota());
  	
  	TipoLista lis = suffisso(cdr(l), check);
  	
  	if (car(l) <= car(lis) && *check) {
      	return cons(car(l), lis);
    } else {
      	*check = false;
      	return lis;
    }
}

int sommaElem(TipoLista l) {
  	if (estVuota(l))
      	return 0;
  	
  	return car(l) + sommaElem(cdr(l));
}

TipoLista modificaLista(TipoLista l, int somma, int prec) {
	if (estVuota(l))
      	return listaVuota();
  	
  	return cons(prec-somma, modificaLista(cdr(l), somma, prec+car(l)));
}

TipoLista precedentiMenoSuffisso(TipoLista l) {
	bool check = true;
  	TipoLista suffix = suffisso(l, &check);
  	int somma = sommaElem(suffix);
  	TipoLista out = modificaLista(l, somma, 0);
  	printf("suffisso: ");
  	printlist(suffix);
  	printf("somma: %d\n", somma);
  	return out;
}

int len(TipoLista l) {
  	if (estVuota(l))
      	return 0;
  	
  	return 1 + len(cdr(l));
}

double* mediaPrecedentiMenoSuffisso(TipoLista* liste, int n){
	double *out = (double *) malloc(sizeof(double)*n);
  	
  	TipoLista l;
  	int somma;
  	for (int i=0; i<n; i++) {
    	l = precedentiMenoSuffisso(liste[i]);
      	somma = sommaElem(l);
      	out[i] = (double)somma / (double)len(l);
    }
  	return out;
}

