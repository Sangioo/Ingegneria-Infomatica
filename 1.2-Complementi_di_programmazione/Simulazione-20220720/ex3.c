
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int camminoMax(TipoAlbero a) {
  	if (estVuoto(a)) {
      	return 0;
    }
  	int sx = camminoMax(sinistro(a));
  	int dx = camminoMax(destro(a));
  	if (estVuoto(sinistro(a)) && estVuoto(destro(a))) {
      	return radice(a) + 0;
    } else if (!estVuoto(sinistro(a)) && estVuoto(destro(a))) {
      	return radice(a) + sx;
    } else if (estVuoto(sinistro(a)) && !estVuoto(destro(a))) {
      	return radice(a) + dx;
    } else if (sx > dx) {
      	return radice(a) + sx;
    } else if (dx > sx) {
      	return radice(a) + dx;
    } else {
      	return radice(a) + sx;
    }
}

TipoAlbero figlio_lontano(TipoAlbero a) {
	if (estVuoto(a)) {
      	return albBinVuoto();
    }
  	int r = camminoMax(a);
  	TipoAlbero sx = figlio_lontano(sinistro(a));
  	TipoAlbero dx = figlio_lontano(destro(a));
	return creaAlbBin(r, sx, dx);
}
