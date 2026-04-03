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

void addSCLC(TipoSCLC *scl, TipoInfoSCLC e) {
    TipoSCLC temp = *scl;
    *scl = (TipoNodoSCLC *) malloc(sizeof(TipoNodoSCLC));
    (*scl)->info = e;
    (*scl)->next = temp;
}

void delSCL(TipoSCL *scl) {
    TipoSCL temp = *scl;
    *scl = (*scl)->next;
    free(temp);
}

void delSCLC(TipoSCLC *scl) {
    TipoSCLC temp = *scl;
    *scl = (*scl)->next;
    free(temp);
}

void writeSCL(TipoSCL scl) {
    if (scl == NULL)
        printf("\n") ;
    else {
        printf("%f ", scl->info);
        writeSCL(scl->next);
    }
}

TipoSCL initSCL(TipoInfoSCL e, int size) {
    TipoSCL scl = NULL;
	for (int i=0; i<size; i++) {
		addSCL(&scl, e);
	}
    return scl;
}

TipoSCL initSCL_rand(int size, int min, int max) {
    TipoSCL scl = NULL;
	for (int i=0; i<size; i++) {
		addSCL(&scl, (rand() % (max - min + 1)) + min);
	}
    return scl;
}

float scl_avg(TipoSCL scl, int *n) {
    if (scl == NULL) {
        return 0;
    } else if (*n == 0) {
        *n += 1;
        float avg = scl->info + scl_avg(scl->next, n);
        return avg / *n;
    } else {
        *n += 1;
        return scl->info + scl_avg(scl->next, n);
    }
}