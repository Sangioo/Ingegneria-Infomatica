#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include"iteratore.h"

// O(1)
IteratoreSCL creaIteratoreSCL(TipoSCL scl) {
  IteratoreSCL it = (IteratoreSCL) malloc (sizeof(scl));
  *it = scl;
  return it;
}

// O(1)
bool hasNext(IteratoreSCL it) {
    return *it!=NULL;
}

// O(1)
T next(IteratoreSCL it) {
    T r = TERRORVALUE;
    if (*it!=NULL) {
        r = (*it)->info;
        *it = (*it)->next;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}

