#pragma once


/**
 * Restituisce la lunghezza della stringa fornita in input.
 * @param s stringa
*/
int mystrlen(char *s);


/**
 * *ESERCIZIO 1:
 * Scrivere una funzione che, dati in ingresso un array vec e la sua lunghezza n, calcoli e restituisca il prodotto degli elementi di vec. (la ricorsione va eseguita sia su vec ed n).
 * @param vec[] array
 * @param n size
*/
float product(float vec[], int n);

/**
 * *ESERCIZIO 2:
 * Scrivere una funzione che scrive in ogni elemento dell’array v[i] la somma di tutti gli elementi che lo precedono da 0 a i-1.
 * @param v[] array
 * @param n size
*/
void vec_integral(float* v, int n);

/**
 * *ESERCIZIO 3:
 * Scrivere la funzione che, data in ingresso una stringa, calcoli e restituisca la lunghezza della stringa.
 * @param s stringa
*/
int length(char * s);

/**
 * *ESERCIZIO 4:
 * Scrivere la funzione che, data  in ingresso una stringa e un carattere, calcoli e restituisca la posizione del primo carattere ch nella stringa. Se il carattere non e' presente, la funzione deve restituire -1.
 * @param s stringa
 * @param ch carattere da cercare
*/
int char_position(char* s, char ch);

/**
 * *ESERCIZIO 4b:
 * Scrivere una funzione che, data  in ingresso una stringa e un carattere, calcoli e restituisca la posizione dell’ultimo carattere ch nella stringa. Se il carattere non e' presente, la funzione deve restituire -1.
 * @param s stringa
 * @param ch carattere da cercare
*/
int char_last_position(char* s, char ch);

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che, data in ingresso una stringa, restituisca true se la stringa contiene solo lettere minuscole, false altrimenti.
 * @param s stringa
*/
bool is_lowercase(char *s);

/**
 * *ESERCIZIO 5b:
 * Scrivere una funzione che, data in ingresso una stringa, restituisca true se la stringa contiene almeno una lettera minuscola, false altrimenti.
 * @param s stringa
*/
bool is_any_lowercase(char *s);

/**
 * *ESERCIZIO 6:
 * Scrivere la funzione che modifica la stringa in ingresso convertendo tutti i caratteri minuscoli in essa presenti nei corrispondenti caratteri maiuscoli.
 * @param s stringa
*/
void to_uppercase(char *s);

/**
 * *ESERCIZIO 7:
 * Scrivere una funzione che, date in ingresso due stringhe, faccia la copia della stringa src dentro  dest. Assumere che la memoria di dest sia già stata allocata e lo spazio sia sufficiente a contenere il risultato.
 * @param dest stringa destinazione
 * @param src stringa sorgente
*/
void copy(char * dest, char * src);

/**
 * *ESERCIZIO 8:
 * Scrivere una funzione che, date in ingresso due stringhe, concateni la stringa src a dest e la memorizzi in dest. Assumere che la memoria di dest sia già stata allocata e lo spazio sia sufficiente a contenere il risultato.
 * @param dest stringa destinazione
 * @param src stringa sorgente
*/
void concat(char * dest, char * src);

/**
 * *ESERCIZIO 9:
 * Scrivere una funzione che dato in input una stringa con un messaggio e un puntatore a file già aperto in scrittura, scriva nel file tutti i caratteri nel messaggio compresi tra ‘a’ e ‘z’ (niente maiuscole, numeri o caratteri speciali).
 * @param message messaggio
 * @param file puntatore a file in scrittura
*/
void filter_write(char * message, FILE * file);

/**
 * *ESERCIZIO 10:
 * Scrivere una funzione che, ricevuti in input due puntatori a file già aperti in lettura, ritorni true se il contenuto dei due file è uguale.
 * @param f1 file 1
 * @param f2 file 2
*/
bool same_content(FILE *f1, FILE *f2);
