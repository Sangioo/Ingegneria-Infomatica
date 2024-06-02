
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


void cambiaNodoAux(TipoAlbero a, int k, int sum) {
	if (a == NULL)
      	return;
    
  	cambiaNodoAux(a->sinistro, k, sum+a->info);
  	cambiaNodoAux(a->destro, k, sum+a->info);
  	
  	if (sum % k == 0)
      	a->info += k;
  	else
      	a->info -= k;
}

void cambiaNodoDalCammino(TipoAlbero a, int k) {
  	cambiaNodoAux(a, k, 0);
}

