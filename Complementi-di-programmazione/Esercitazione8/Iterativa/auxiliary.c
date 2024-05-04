#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "auxiliary.h"

/**
 * Crea un insieme vuoto, O(1)
 * @returns un insieme vuoto
*/
Insieme insiemeVuoto() {
  return NULL;
}

/**
 * Verifica che un insieme sia vuoto o meno, O(1)
 * @param ins insieme da valutare
 * @returns true se l'insieme e' vuoto, false altrimenti
*/
bool estVuoto(Insieme ins) {
    return ins == NULL;
}

/**
 * Inserisce un elemento nell'insieme, O(n)
 * @param ins insieme a cui aggiungere l'elemento
 * @param e elemento da aggiungere
 * @returns un'insieme costituito dall'insieme in input con aggiunto l'elemento
*/
Insieme inserisci(Insieme ins, T e) {
    if (!membro(ins,e)) {
        TipoNodo* n = (TipoNodo*) malloc(sizeof(TipoNodo));
        n->info = e;
        n->next = ins;
        return n;
    }
    else
        return ins;
}

/**
 * Elimina l'elemento specificato dall'insieme, O(n)
 * @param ins insieme da cui eliminare
 * @param e elemento da eliminare
 * @returns un insieme privo dell'elemento, se l'elemento non e' presente ritorna l'insieme di input
*/
Insieme elimina(Insieme ins, T e) {
    if (!membro(ins,e))
        return ins;
    else if (ins->info == e) {
      return ins->next; // non si deve deallocare memoria
    }
    else {
        TipoNodo* n = (TipoNodo*) malloc(sizeof(TipoNodo));
        n->info = ins->info;
        n->next = elimina(ins->next,e);
        return n;
    }
}

/**
 * Verifica che l'elemento specificato sia presente nell'insieme, O(n)
 * @param ins insieme in input
 * @param e elemento da cercare
 * @returns true se l'elemento e' presente, false altrimenti
*/
bool membro(Insieme ins, T e) {
    if (estVuoto(ins))
        return false;
    else
        return ins->info==e || membro(ins->next, e);
}

/**
 * Crea un iteratore per l'insieme, O(1)
 * @param ins l'insieme per cui creare l'iteratore
 * @returns l'iteratore per l'insieme specificato
*/
IteratoreInsieme creaIteratoreInsieme(Insieme ins) {
  IteratoreInsieme it = (IteratoreInsieme) malloc (sizeof(Insieme));
  *it = ins;
  return it;
}

/**
 * Verifica che sia presente un altro elemento nell'insieme, O(1)
 * @param it iteratore per l'insieme
 * @returns true se e' presente un altro elemento, false altrimenti
*/
bool hasNext(IteratoreInsieme it) {
    return *it!=NULL;
}

/**
 * Restituisce il valore dell'elemento corrente nell'insieme, O(1)
 * @param it iteratore per l'insieme
 * @returns il valore dell'elemento se e' presente, TERRORVALUE altrimenti
*/
T next(IteratoreInsieme it) {
    T r = TERRORVALUE;
    if (*it!=NULL) {
        r = (*it)->info;
        *it = (*it)->next;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}