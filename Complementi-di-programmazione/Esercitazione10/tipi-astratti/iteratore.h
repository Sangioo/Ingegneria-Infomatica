#ifndef ITERATORE_H
#define ITERATORE_H

#include "scl.h"

// Valore errore di tipo T (per iteratore)
#define TERRORVALUE -999999

typedef TipoNodo* TipoSCL;
typedef TipoSCL* IteratoreSCL;

// Iteratore:
IteratoreSCL creaIteratoreSCL(TipoSCL scl);
bool hasNext(IteratoreSCL it);
T next(IteratoreSCL it);

#endif

