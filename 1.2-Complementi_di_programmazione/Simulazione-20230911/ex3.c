
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int distMinDisc(TipoAlbero a, int* min) {
	if (estVuoto(a))
      	return 0;
  
  	int min_sx = radice(a), min_dx = radice(a);
  	int sx = distMinDisc(sinistro(a), &min_sx);
  	int dx = distMinDisc(destro(a), &min_dx);
  	
  	if (radice(a) < min_sx && radice(a) < min_dx) {
      	*min = radice(a);
  		return 1;
    } else if (min_sx <= min_dx) {
      	*min = min_sx;
      	return 1 + sx;
    } else {
      	*min = min_dx;
      	return 1 + dx;
    }
}


void diff_aux(TipoAlbero a, int max, int dist) {
	if (a == NULL)
      	return;
  	
  	int ms = 0, md = 0;
  	int dist_sx = distMinDisc(a->sinistro, &ms);
  	int dist_dx = distMinDisc(a->destro, &md);
    int t = a->info;
  	
  	if (a->sinistro != NULL && a->destro == NULL) {
  		a->info = dist + dist_sx;
    } else if (a->sinistro == NULL && a->destro != NULL) {
      	a->info = dist + dist_dx;
    } else if (ms < md) {
      	a->info = dist + dist_sx;
    } else if (ms > md) {
      	a->info = dist + dist_dx;
    } else {
      	if (dist_sx >= dist_dx) {
          	a->info = dist + dist_sx;
        } else {
          	a->info = dist + dist_dx;
        }
    }
  		
  	if (t > max) {
      	max = t;
      	dist = 0;
    }
  	
  	diff_aux(a->sinistro, max, dist+1);
  	diff_aux(a->destro, max, dist+1);
}


void diffMinFogliaMaxAntenato(TipoAlbero a) {
  	diff_aux(a, 0, 0);
}

