#include <stdio.h>
#include <stdlib.h>

#include "auxiliary.h"


// Valore di errore
TipoInfoAlbero ERRORE_InfoAlbBin='*';


// Implementazioni del tipo astratto

TipoAlbero albBinVuoto() {
  return NULL;
}

TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx) {
    TipoAlbero a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
    a->info = info;
    a->sinistro = sx;
    a->destro = dx;
    return a;
}


bool estVuoto(TipoAlbero a) {
    return (a == NULL);
}

TipoInfoAlbero radice(TipoAlbero a) {
    if (a == NULL) {
        printf ("ERRORE accesso albero vuoto \n");
        return ERRORE_InfoAlbBin;
    } else {
        return a->info;
    }
}


TipoAlbero sinistro(TipoAlbero a) {
    if (a == NULL) {
        printf ("ERRORE accesso albero vuoto \n");
        return NULL;
    } else {
        return a->sinistro;
    }
}

TipoAlbero destro(TipoAlbero a) {
    if (a == NULL) {
        printf ("ERRORE accesso albero vuoto \n");
        return NULL;
    } else {
        return a->destro;
    }
}


void assegnaRadice(TipoAlbero a, TipoInfoAlbero info) {
	if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return;
	}
	a->info = info;
}


// Funzioni esterne

void stampaParentetica(TipoAlbero a) {
    if (estVuoto(a)) {
        printf("()");
    }
    else {
        printf("( %d ", radice(a));
        stampaParentetica(sinistro(a));
        printf(" ");
        stampaParentetica(destro(a));
        printf(" )");
    }
}

TipoAlbero initAlbero_aux(FILE *file_albero) {
    char c;
    TipoInfoAlbero i;
    TipoAlbero r;
    
    // legge la parentesi aperta
    c = fgetc(file_albero);

    // carattere successivo
    c = fgetc(file_albero);
    if (c == ')')
        // se legge () allora l’albero e' vuoto
        return NULL;
    else {
        // altrimenti crea il nodo
        i = c - 48;
    
        r = (TipoAlbero) malloc(sizeof(TipoNodoAlbero)); 
        r->info = i;

        // legge i sottoalberi
        r->sinistro = initAlbero_aux(file_albero);
        r->destro = initAlbero_aux(file_albero);
        
        // carattere successivo
        c = fgetc(file_albero);
        return r;
    }
}

TipoAlbero initAlbero(char *nome_file) {
    TipoAlbero result;
    FILE *file_albero;
    file_albero = fopen(nome_file, "r");
    result = initAlbero_aux(file_albero);
    fclose(file_albero);
    return result;
}

bool isFoglia(TipoAlbero a) {
    return estVuoto(sinistro(a)) && estVuoto(destro(a));
}
