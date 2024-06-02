
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int contaPari_somma(TipoAlbero a, int *somma) {
	if (estVuoto(a)) {
      	return 0;
    }
  	*somma += radice(a);
  	if (radice(a)%2 == 0)
      	return 1 + contaPari_somma(sinistro(a), somma) + contaPari_somma(destro(a), somma);
  	else
      	return contaPari_somma(sinistro(a), somma) + contaPari_somma(destro(a), somma);
}

TipoAlbero maxMenoMinPari(TipoAlbero a) {
	if (estVuoto(a))
      	return albBinVuoto();
  	
 	int somma_sx = 0, somma_dx = 0;
  	int n_sx = contaPari_somma(sinistro(a), &somma_sx);
  	int n_dx = contaPari_somma(destro(a), &somma_dx);
  	int r;
  	if (n_sx < n_dx) {
      	r = somma_dx - somma_sx;
    } else {
      	r = somma_sx - somma_dx;
    }
  	return creaAlbBin(r, maxMenoMinPari(sinistro(a)), maxMenoMinPari(destro(a)));
}

