/*****************************
* Tipo astratto pila.        *
*                            *
* Realizzazione side-effect. *
*****************************/
#pragma once

#include <stdbool.h>
#include "scl.h"

typedef TipoNodo * Pila;


Pila * pilaVuota();                // nuova pila vuota
bool estPilaVuota(Pila *c);        // controlla se vuota
void inPila(Pila *p , T e);        // push; inserisce in testa
T outPila(Pila* p);                // pop; rimuove dalla testa
T primoPila(Pila* p);              // valore del primo

bool membro(int e, const int *arr, int n);
Pila* pilaInit(int len, int upper, int lower);
void printPila(Pila *p);

void stampa_sequenza_inversa();
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n);
bool check_palindrome(const char* s);
bool check_palindrome_r(const char* s);
int* rimuoviMinori(int* arr, int len);