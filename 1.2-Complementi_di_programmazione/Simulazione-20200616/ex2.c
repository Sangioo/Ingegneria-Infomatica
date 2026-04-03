#include "aux.h"

int contaDecrescenti(TipoSCL lis){
	if (lis == NULL || lis->next == NULL) {
      	return 0;
    }
  	if (lis->info > lis->next->info) {
      	return 1 + contaDecrescenti(lis->next);
    }
  	return contaDecrescenti(lis->next);
}

void append(TipoSCL *l, TipoInfoSCL e) {
 	if (*l == NULL) {
      	TipoSCL t = (TipoSCL) malloc(sizeof(TipoNodoSCL));
      	t->info = e;
      	t->next = NULL;
      	*l = t;
      	return;
    }
  	append(&((*l)->next), e);
}

int mergeSequenziale(TipoSCL lis1, TipoSCL lis2){
	TipoSCL l = NULL;
  	int i = 0;
  	while (lis1 != NULL && lis2 != NULL) {
    	if (i == 0) {
			append(&l, lis1->info);
          	lis1 = lis1->next;
        } else {
          	append(&l, lis2->info);
          	lis2 = lis2->next;
        }
      	i = (i+1)%2;
    }
  	while (lis1 != NULL) {
      	append(&l, lis1->info);
        lis1 = lis1->next;
    }
  	while (lis2 != NULL) {
      	append(&l, lis2->info);
        lis2 = lis2->next;
    }
  	
  	return contaDecrescenti(l);
}