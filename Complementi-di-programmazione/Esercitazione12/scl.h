#pragma once

typedef int TipoInfoSCL;
struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL *TipoLista;

void addSCL(TipoLista *scl, TipoInfoSCL e);
void delSCL(TipoLista *scl);
void writeSCL(TipoLista scl);
TipoLista initSCL(TipoInfoSCL e, int size);
void fondi(TipoLista scl1, TipoLista *scl2);
int length(TipoLista scl);
TipoLista atLivello(TipoLista scl, int livello);
int index(TipoLista scl, int livello);