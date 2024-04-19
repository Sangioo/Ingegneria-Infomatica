#pragma once

typedef float TipoInfoSCL;
struct ElemSCL {
    TipoInfoSCL info;
    struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

// typedef char TipoInfoSCL;


void addSCL(TipoSCL *scl, TipoInfoSCL e);

void delSCL(TipoSCL *scl);

int emptySCL(TipoSCL scl);

void writeSCL(TipoSCL scl);

TipoSCL initSCL(TipoInfoSCL e, int size);

TipoSCL initSCL_rand(int size, int min, int max);


/**
 * *ESERCIZIO 1:
 * Implementare la funzione che calcola la lunghezza struttura collegata scl.
 * @param scl struttura collegata lineare input
*/
int scl_len(TipoSCL scl);

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che calcola la somma degli elementi contenuti nella lista scl.
 * @param scl struttura collegata lineare input
*/
float scl_sum(TipoSCL scl);

/**
 * *ESERCIZIO 3:
 * Implementare la funzione che restituisce il valore medio degli elementi della lista. L’esercizio deve essere svolto senza l’ausilio delle precedenti due funzioni.
 * @param scl struttura collegata lineare input
*/
float scl_media(TipoSCL scl);

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che ritorna il prodotto scalare, risultato della moltiplicazione degli elementi delle due liste.
 * @param scl1 struttura collegata lineare numero 1
 * @param scl1 struttura collegata lineare numero 2
*/
float scl_dot(TipoSCL scl1, TipoSCL scl2);

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che modifichi la SCL in input duplicando l’elemento in posizione pos (si inserisca un nuovo nodo un nodo nella posizione successiva).
 * @param scl struttura collegata lineare input
 * @param pos posizione
*/
void scl_duplicate_pos(TipoSCL scl, int pos);

/**
 * *ESERCIZIO 6:
 * Scrivere una funzione che modifica la SCL ris contenente solo gli elementi con valori maggiori o uguali di zero di scl.
 * @param scl struttura collegata lineare input
 * @param ris struttura collegata lineare da modificare
*/
void scl_positives(TipoSCL scl, TipoSCL *ris);

/**
 * *ESERCIZIO 6b:
 * Scrivere una funzione che ritorna una nuova SCL contenente solo gli elementi con valori maggiori o uguali di zero di scl.
 * @param scl struttura collegata lineare input
*/
TipoSCL scl_positives_(TipoSCL scl);

/**
 * *ESERCIZIO 7:
 * Scrivere la funzione che data in input la struttura s, ne stampi a schermo tutti i caratteri. Una SCL vuota corrisponderà alla stringa vuota "".
 * @param s struttura collegata lineare input
*/
void sclstring_print(TipoSCL s);

/**
 * *ESERCIZIO 8:
 * Scrivere una funzione che data in input una stringa, generi una struttura SCL che la rappresenti.
 * @param s stringa input
 * @param ris struttura collegata lineare output
*/
void sclstring_create(const char *s, TipoSCL *ris);

/**
 * *ESERCIZIO 8b:
 * Scrivere una funzione che data in input una stringa, ritorni una struttura SCL che la rappresenti.
 * @param s stringa input
*/
TipoSCL sclstring_create_(const char *s);

/**
 * *ESERCIZIO 9:
 * Scrivere una funzione che restituisca true se e solo se la stringa rappresentata da scl è uguale a s.
 * @param scl struttura collegata lineare input
 * @param s stringa input
*/
bool sclstring_equals(TipoSCL scl, const char *s);

/**
 * *ESERCIZIO 10:
 * Scrivere una funzione che modifichi la struttura puntata da scl_p, eliminando tutti gli elementi con valore uguale a val. Se val non è presente, non va fatta alcuna modifica.
 * @param scl_p puntatore a struttura collegata lineare input
 * @param val carattere da matchare
*/
void sclstring_remove(TipoSCL *scl_p, char val);
