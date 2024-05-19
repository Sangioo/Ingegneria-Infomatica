#pragma once

#include <stdbool.h>
#include "scl.h"


// Tipo info dell'albero
typedef int TipoInfoAlbero;

// Albero con strutture collegate
typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx);
bool estVuoto(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);
void assegnaRadice(TipoAlbero a, TipoInfoAlbero info);

void stampaParentetica(TipoAlbero a);
TipoAlbero initAlbero(char *a);
bool isFoglia(TipoAlbero a);
int minimo(TipoAlbero a);
int minimo_aux(TipoAlbero a);
void delAlbero(TipoAlbero *a);


void rimuovi_minimo(TipoAlbero *a);