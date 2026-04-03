
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


TipoAlbero limita_aux(TipoAlbero a, int k, int sum) {
	if (estVuoto(a))
      	return albBinVuoto();
  	
  	TipoAlbero sx = limita_aux(sinistro(a), k, sum+radice(a));
  	TipoAlbero dx = limita_aux(destro(a), k, sum+radice(a));
  
  	if (sum+radice(a) <= k)
      	return creaAlbBin(radice(a), sx, dx);
  	else
      	return creaAlbBin(0, sx, dx);
}

TipoAlbero limita_albero(TipoAlbero a, int k) {
	return limita_aux(a, k, 0);
}
