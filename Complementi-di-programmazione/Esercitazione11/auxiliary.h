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


TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero trova_massimo_aux(TipoAlbero a);

TipoInfoAlbero somma_foglie(TipoAlbero a);

int cerca_livello(TipoAlbero a, TipoInfoAlbero v);

int conta_dispari(TipoAlbero a);

int somma_singoli(TipoAlbero a);

TipoLista albero_lista(TipoAlbero a);

TipoLista percorso_lungo(TipoAlbero a);

void somma_sottoalbero(TipoAlbero a);

void scambia_foglie(TipoAlbero a);

void max_figli_livello(TipoAlbero a, int livello);

void scambia_foglie_livello(TipoAlbero a, int livello);

TipoAlbero set_albero(TipoLista l, int start, int end);
void set_albbinric(TipoAlbero *a, TipoLista l);