#include "aux.h"

TipoInfoAlbero sommaMassimaPercorso(TipoAlbero a){
	if (estVuoto(a))
      	return 0;
	
  	int dx = sommaMassimaPercorso(sinistro(a));
  	int sx = sommaMassimaPercorso(destro(a));
  	
  	if (sx > dx)
      	return radice(a) + sx;
 	else
  		return radice(a) + dx;
}
