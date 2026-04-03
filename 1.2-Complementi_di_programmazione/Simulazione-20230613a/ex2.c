#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

void delSCL(TipoLista *l) {
  	TipoLista t = *l;
  	*l = (*l)->next;
  	free(t);
}

void append(TipoLista *l, T e) {
  	if (*l == NULL) {
		*l = (TipoLista) malloc(sizeof(TipoNodo));
      	(*l)->info = e;
    	(*l)->next = NULL;
      	return;
    }
  	append(&((*l)->next), e);
}

void modificaLista(TipoLista* l, int k) {
	if (*l == NULL) {
      	return;
    }
  	if (k == 0) {
      	return;
    }
  	append(l, (*l)->info);
  	delSCL(l);
  	modificaLista(l, k-1);
}

int sommaPesata(TipoLista l, int i) {
	if (l == NULL) {
      	return 0;
    }
  	return l->info * i + sommaPesata(l->next, i+1);
}

double mediaSommaPesataModificaListe(TipoLista* liste, int* v, int n) {
  	double sum = 0;
	for (int i=0; i<n; i++) {
    	modificaLista(&liste[i], v[i]);
      	sum += sommaPesata(liste[i], 1);
    }
  	return sum / (double)n;
}
