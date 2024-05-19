#include <stdio.h>
#include <stdlib.h>
#include "scl.h"

void addSCL(TipoLista *scl, TipoInfoSCL e) {
    TipoLista temp = *scl;
    *scl = (TipoNodoSCL *) malloc(sizeof(TipoNodoSCL));
    (*scl)->info = e;
    (*scl)->next = temp;
}

void delSCL(TipoLista *scl) {
    TipoLista temp = *scl;
    *scl = (*scl)->next;
    free(temp);
}

void writeSCL(TipoLista scl) {
    if (scl == NULL)
        printf("\n") ;
    else {
        printf("%d ", scl->info);
        writeSCL(scl->next);
    }
}

TipoLista initSCL(TipoInfoSCL e, int size) {
    TipoLista scl = NULL;
	for (int i=0; i<size; i++) {
		addSCL(&scl, e);
	}
    return scl;
}

// void fondi(TipoLista scl1, TipoLista scl2) {
//     if (scl1->next == NULL) {
//         scl1->next = scl2;
//     } else {
//         fondi(scl1->next, scl2);
//     }
// }
void fondi(TipoLista scl1, TipoLista *scl2) {
    if (scl1 == NULL) {
        return;
    } else {
        fondi(scl1->next, scl2);
        addSCL(scl2, scl1->info);
    }
}

int length(TipoLista scl) {
    if (scl == NULL) {
        return 0;
    } else {
        return 1 + length(scl->next);
    }
}

// TipoLista atLivello(TipoLista scl, int livello) {
//     if (scl == NULL) {
//         return NULL;
//     } else if (livello == 0) {
//         return scl;
//     } else {
//         return atLivello(scl->next, livello-1);
//     }
// }

int index(TipoLista scl, int livello) {
    if (scl == NULL) {
        return -1;
    } else if (livello == 0) {
        return scl->info;
    } else {
        return index(scl->next, livello-1);
    }
}