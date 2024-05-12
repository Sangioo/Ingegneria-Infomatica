/*****************************
* Tipo astratto coda.        *
*                            *
* Realizzazione side-effect. *
*****************************/
#pragma once

#include <stdbool.h>

#include "scl.h"

typedef TipoNodo * Coda;

Coda * codaVuota();             // nuova coda vuota
bool estCodaVuota(Coda *c);     // controlla se vuota
void inCoda(Coda *c , T e);     // inserisce in coda
T outCoda(Coda *c);             // rimuove dalla testa
T primoCoda(Coda *c);           // valore del primo

Coda* initCoda(int len, int lower, int upper);
void printCoda(Coda *c);

void stampa_sequenza();
int elemento_iesimo(Coda *c, int pos);
void avoid_stampa(Coda *c, int elem);
Coda * coda_circolare(Coda *c, int n);
Coda * elementi_pari(Coda *c);