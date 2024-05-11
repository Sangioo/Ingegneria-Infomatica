#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "auxiliary.h"

bool isemptySCL(TipoSCL scl) {
    return scl == NULL;
}

bool isemptySCLC(TipoSCLC s) {
    return s == NULL;
}

TipoInfoSCL primoSCL(TipoSCL scl) {
    if (!isemptySCL(scl))
        return scl->info;
    else {
        printf("primo di una lista vuota");
        return 0;
    }
}

TipoInfoSCLC primoSCLC(TipoSCLC s) {
    if (!isemptySCLC(s))
        return s->info;
    else {
        printf("primo di una lista vuota");
        return 0;
    }
}

TipoSCL restoSCL(TipoSCL scl) {
    if (!isemptySCL(scl)) {
        return scl->next;
    } else {
        printf("resto di una lista vuota");
        return NULL;
    }
}

TipoSCLC restoSCLC(TipoSCLC s) {
    if (!isemptySCLC(s)) {
        return s->next;
    } else {
        printf("resto di una lista vuota");
        return NULL;
    }
}

TipoSCL addSCL(TipoSCL scl, TipoInfoSCL e) {
    TipoSCL temp = (TipoNodoSCL *) malloc(sizeof(TipoNodoSCL));
    temp->info = e;
    temp->next = scl;
    return temp;
}

TipoSCLC addSCLC(TipoSCLC s, TipoInfoSCLC e) {
    TipoSCLC temp = (TipoNodoSCLC *) malloc(sizeof(TipoNodoSCLC));
    temp->info = e;
    temp->next = s;
    return temp;
}

void writeSCL(TipoSCL scl) {
    if (isemptySCL(scl))
        printf("\n");
    else {
        printf("%f ", primoSCL(scl));
        writeSCL(restoSCL(scl));
    }
}

TipoSCL initSCL(TipoInfoSCL e, int size) {
    TipoSCL scl = NULL;
	for (int i=0; i<size; i++) {
		scl = addSCL(scl, e);
	}
    return scl;
}

TipoSCL initSCL_rand(int size, int min, int max) {
    TipoSCL scl = NULL;
	for (int i=0; i<size; i++) {
		scl = addSCL(scl, (rand() % (max - min + 1)) + min);
	}
    return scl;
}