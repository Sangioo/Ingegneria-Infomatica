#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 1:
 * Implementare la funzione che legge una sequenza di numeri inseriti da tastiera.
 * Quando in input viene inserito un numero negativo, la sequenza termina, e la funzione deve stampare in output tutta la sequenza inserita fino a quel momento, in ordine inverso.
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
 * Scrivere una funzione che riceve una pila p, e un array rimuovere di lunghezza n.
 * La funzione deve ripetutamente controllare se il primo elemento di p è presente in rimuovere, e eventualmente rimuoverlo dalla pila.
 * Questo processo termina al primo elemento che non viene trovato in rimuovere.
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
 * Scrivere la funzione che, data una stringa in input, restituisce true se la stringa rappresenta un’espressione palindroma di lunghezza pari.
 * Se s è vuota, si restituisca true.
 * E’ consentito l’utilizzo di strlen.
 * La funzione deve accedere agli elementi una sola volta, accedendo ordinatamente dal primo all’ultimo.
 * @param s stringa da controllare
 * @returns true se la stringa e' palindroma e ha lunghezza pari, false altrimenti
*/
bool check_palindrome(const char* s) {
    int len = strlen(s);
    Pila *p = pilaVuota();

    if (len%2 != 0) return false;

    for (int i=0; i<len; i++) {
        if (i < len/2) {
            inPila(p, s[i]);
        } else if (outPila(p) != s[i]) {
            return false;
        }
    }
    return true;
}

/**
 * *ESERCIZIO 4:
 * Scrivere la funzione che effettua lo stesso calcolo di check_palindrome.
 * check_palindrome_r deve essere ricorsiva, e non utilizzare alcuna pila. E’ ancora permesso l’uso di strlen.
 * @param s stringa da controllare
 * @returns true se la stringa e' palindroma e ha lunghezza pari, false altrimenti
*/
bool palindromer(const char *s, int i, int end) {
    if (i == end/2) {
        return true;
    } else if (s[i] != s[end-i-1]) {
        return false;
    } else {
        return palindromer(s, ++i, end);
    }
}
/**
 * *ESERCIZIO 4:
 * Scrivere la funzione che effettua lo stesso calcolo di check_palindrome.
 * check_palindrome_r deve essere ricorsiva, e non utilizzare alcuna pila. E’ ancora permesso l’uso di strlen.
 * @param s stringa da controllare
 * @returns true se la stringa e' palindroma e ha lunghezza pari, false altrimenti
*/
bool check_palindrome_r(const char* s) {
    if (strlen(s)%2 != 0) return false;
    return palindromer(s, 0, strlen(s));
}

/**
 * *ESERCIZIO 5:
 * Scrivere la funzione che, dati in input un array arr, contenente una sequenza di numeri, e la sua lunghezza len, restituisce un array costruito nel seguente modo usando una pila:
 * 1. Aggiungere i numeri alla pila uno alla volta
 * 2. Ogni volta che il numero successivo è minore dell’ultimo numero inserito nella pila, rimuovere ciascun elemento della pila che è maggiore di tale numero fermandosi al primo elemento minore o uguale, dunque inserire il prossimo numero nell’array.
 * @param arr[] array in input
 * @param len lunghezza di arr[]
 * @returns l'array processato
*/
int* rimuoviMinori(int* arr, int len, int *out_len) {
    Pila *p = pilaVuota();
    int n = 1;
    int *out;

    inPila(p, arr[0]);
    for (int i=1; i<len; i++) {
        if (primoPila(p) > arr[i]) {
            while (!estPilaVuota(p) && primoPila(p) > arr[i]) {
                outPila(p);
                n--;
            }
        }
        inPila(p, arr[i]);
        n++;
    }

    *out_len = n;
    out = (int *) malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        out[i] = outPila(p);
    }

    return out;
}


void test1() {
    printf("\nTEST ESERCIZIO 1:\n");
    // stampa_sequenza_inversa();
}

void test2() {
	printf("\nTEST ESERCIZIO 2:\n");
    const int n = 9;
    const int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Pila *p = pilaInit(10, 0, 10);

    printf("pila iniziale: ");
    printPila(p);
    printf("array: ");
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    rimuovi_alcuni(p, arr, n);
    printf("pila modificata: ");
    printPila(p);
}

void test3() {
	printf("\nTEST ESERCIZIO 3:\n");
    const char *s = "Lorem ipsum dorem sit amet";
    // const char *s = "aaaabbbbaaaa";
    const char *pal = check_palindrome(s) ? "true" : "false";

    printf("stringa: %s\n", s);
    printf("palindroma: %s\n", pal);
}

void test4() {
	printf("\nTEST ESERCIZIO 4:\n");
    const char *s = "Lorem ipsum dorem sit amet";
    // const char *s = "aaaabbbbaaaa";
    const char *pal = check_palindrome_r(s) ? "true" : "false";

    printf("stringa: %s\n", s);
    printf("palindroma: %s\n", pal);
}

void test5() {
	printf("\nTEST ESERCIZIO 5:\n");
    const int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4};

    printf("array: ");
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    int l = 0;
    int *out = rimuoviMinori(arr, n, &l);
    printf("array output: ");
    for (int i=0; i<l; i++) printf("%d ", out[i]);
    printf("\n");
}