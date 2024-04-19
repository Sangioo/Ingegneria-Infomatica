#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "auxiliary.h"

void addSCL(TipoSCL *scl, TipoInfoSCL e) {
    TipoSCL temp = *scl;
    *scl = (TipoNodoSCL *) malloc(sizeof(TipoNodoSCL));
    (*scl)->info = e;
    (*scl)->next = temp;
}

void delSCL(TipoSCL *scl) {
    TipoSCL temp = *scl;
    *scl = (*scl)->next;
    free(temp);
}

int emptySCL(TipoSCL scl) {
    return scl == NULL;
}

void writeSCL(TipoSCL scl) {
    if (emptySCL(scl))
        printf("\n") ;
    else {
        printf("%f ", scl->info);
        writeSCL(scl->next);
    }
}

TipoSCL initSCL(TipoInfoSCL e, int size) {
    TipoSCL scl = (TipoNodoSCL *) malloc(sizeof(TipoNodoSCL));
	scl->info = e;
	scl->next = NULL;
	for (int i=0; i<size-1; i++) {
		addSCL(&scl, e);
	}
    return scl;
}

TipoSCL initSCL_rand(int size, int min, int max) {
    TipoSCL scl = (TipoNodoSCL *) malloc(sizeof(TipoNodoSCL));
	scl->info = (rand() + min) % max;
	scl->next = NULL;
	for (int i=0; i<size-1; i++) {
		addSCL(&scl, (rand() + min) % max);
	}
    return scl;
}