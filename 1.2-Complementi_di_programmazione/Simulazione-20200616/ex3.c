#include "aux.h"


void nodoDivisibile(TipoAlbero a) {
    if (estVuoto(a)) {
      	return;
    }
  	bool sx = !estVuoto(sinistro(a)) && radice(sinistro(a)) != 0 && radice(a) % radice(sinistro(a)) == 0;
  	bool dx = !estVuoto(destro(a)) && radice(destro(a)) != 0 && radice(a) % radice(destro(a)) == 0;
  	if (sx || dx) {
      	a->info = 1;
    }
	nodoDivisibile(sinistro(a));
  	nodoDivisibile(destro(a));
}


