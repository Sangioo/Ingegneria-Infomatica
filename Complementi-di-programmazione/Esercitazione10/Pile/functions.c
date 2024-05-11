#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 1:
 * Implementare la funzione che legge una sequenza di numeri inseriti da tastiera. Quando in input viene inserito un numero negativo, la sequenza termina, e la funzione deve stampare in output tutta la sequenza inserita fino a quel momento, in ordine inverso.
*/
void stampa_sequenza_inversa() {
    int in = 0;
    Pila *p = pilaVuota();

    printf("inserire numero: ");
    scanf("%d", &in);
    while (in >= 0) {
        inPila(p, in);
        printf("inserire numero: ");
        scanf("%d", &in);
    }

    printf("sequenza invertita: ");
    while (!estPilaVuota(p)) {
        printf("%d ", outPila(p));
    }
    printf("\n");
}

/**
 * *ESERCIZIO 2:
 * Scrivere una funzione che riceve una pila p, e un array rimuovere di lunghezza n. La funzione deve ripetutamente controllare se il primo elemento di p è presente in rimuovere, e eventualmente rimuoverlo dalla pila. Questo processo termina al primo elemento che non viene trovato in rimuovere.
 * @param *p lista da cui rimuovere
 * @param rimuovere[] array di elementi da rimuovere
 * @param n lunghezza dell'array rimuovere[]
*/
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n) {
    while (!estPilaVuota(p)) {
        T e = primoPila(p);
        if (membro(e, rimuovere, n)) {
            outPila(p);
        } else {
            return;
        }
    }
}

/**
 * *ESERCIZIO 3:
 * Scrivere la funzione che, data una stringa in input, restituisce true se la stringa rappresenta un’espressione palindroma di lunghezza pari. Se s è vuota, si restituisca true. E’ consentito l’utilizzo di strlen. La funzione deve accedere agli elementi una sola volta, accedendo ordinatamente dal primo all’ultimo.
 * @param s stringa da controllare
 * @returns true se la stringa e' palindroma e ha lunghezza pari, false altrimenti
*/
// bool check_palindrome(const char* s);

/**
 * *ESERCIZIO 4:
 * Scrivere la funzione che effettua lo stesso calcolo di check_palindrome. check_palindrome_r deve essere ricorsiva, e non utilizzare alcuna pila. E’ ancora permesso l’uso di strlen.
 * @param s stringa da controllare
 * @returns true se la stringa e' palindroma e ha lunghezza pari, false altrimenti
*/
// bool check_palindrome_r(const char* s);

/**
 * *ESERCIZIO 5:
 * Scrivere la funzione che, dati in input un array arr, contenente una sequenza di numeri, e la sua lunghezza len, restituisce un array costruito nel seguente modo usando una pila:
 * 1. Aggiungere i numeri alla pila uno alla volta
 * 2. Ogni volta che il numero successivo è minore dell’ultimo numero inserito nella pila, rimuovere ciascun elemento della pila che è maggiore di tale numero fermandosi al primo elemento minore o uguale, dunque inserire il prossimo numero nell’array.
 * @param arr[] array in input
 * @param len lunghezza di arr[]
 * @returns l'array processato
*/
// int* rimuoviMinori(int* arr, int len);


void test1() {
    printf("\nTEST ESERCIZIO 1:\n");
    stampa_sequenza_inversa();
}

void test2() {
	printf("\nTEST ESERCIZIO 2:\n");
    const int n = 5;
    const int arr[n] = {1, 2, 3, 4, 5};
    Pila *p = pilaInit(10, 0, 50);

    rimuovi_alcuni(p, arr, n);
    printPila(p);
}

void test3() {
	printf("\nTEST ESERCIZIO 3:\n");
    
}

void test4() {
	printf("\nTEST ESERCIZIO 4:\n");
    
}

void test5() {
	printf("\nTEST ESERCIZIO 5:\n");
    
}