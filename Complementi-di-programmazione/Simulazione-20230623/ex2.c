
#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l))
      	return cons(e, NULL);
    
  	return cons(car(l), append(cdr(l), e));
}

TipoLista ruota(TipoLista l) {
  	if (estVuota(l))
      	return NULL;
  
  	return append(cdr(l), car(l));
}


TipoLista combinazione(TipoLista lucchetto, int password) {
	if (estVuota(lucchetto)) {
      	return lucchetto;
    }
  	
  	lucchetto = ruota(lucchetto);
  	while (car(lucchetto) != password) {
    	lucchetto = ruota(lucchetto);
    }
  
  	return lucchetto;
}
