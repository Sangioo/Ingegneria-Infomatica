#include "aux.h"

int find(TipoSCL lis, int x) {
	if (lis == NULL)
      	return -1;
  
  	if (x == 0)
      	return lis->info;
  
  	return find(lis->next, x-1);
}

int sommaElementi(TipoSCL lis, int i, int j){
	int elem_i = find(lis, i);
  	int elem_j = find(lis, j);
  	if (elem_i == -1 || elem_j == -1)
      	return -1;
  	
  	return elem_i + elem_j;
}

void sommatoriaAux(TipoSCL l, TipoSCL r, int i) {
	if (r == NULL)
      	return;
  	
  	if (i % 2 == 1 && i > 1)
      	r->info = sommaElementi(l, i-2, i);
    
  	sommatoriaAux(l, r->next, i+1);
}

void sommatoriaDispari(TipoSCL lis, TipoSCL ris){
	sommatoriaAux(ris, ris, 0);
}

