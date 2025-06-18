#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score, trials;

char * convert2string(struct destinazione * list){
    // Calcolo la lunghezza totale necessaria per la stringa
    int total_length = 0;
    struct destinazione *current = list;
    while (current != NULL) {
        total_length += strlen(current->destinazione);
        current = current->next;
    }
    
    // Alloco la memoria per la stringa risultante (+1 per il terminatore null)
    char *result = (char *)malloc(total_length + 1);
    if (result == NULL) {
        return NULL; // Gestione errore di allocazione memoria
    }
    
    // Concateno le destinazioni nella stringa risultante
    result[0] = '\0'; // Inizializzo la stringa vuota
    current = list;
    while (current != NULL) {
        strcat(result, current->destinazione);
        current = current->next;
    }
    
    return result;
}

void freeList(struct destinazione ** list) {
    struct destinazione * current = *list;
    while (current != NULL) {
        struct destinazione *next = current->next;
        free(current);
        current = next;
    }
    *list=NULL;
}

static void test(const char * file, const char * part, const int budget, const char * correct) {
    trials++;
    struct destinazione * list = NULL;
    destinazioniDisponibili(file, part, budget, &list);
    char* out = convert2string(list);
    int ok = strcmp(correct, out) == 0;
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
    freeList(&list);
    if (out) free(out);
}

int main() {
    test("booked.txt", "ROM", 200, "MIL");
    test("booked.txt", "BER", 600, "");
    test("booked.txt", "ROM", 600, "VENMADPARMILLON");
    test("booked.txt", "MIL", 800, "PARROMLON");
    test("booked.txt", "MIL", 100, "");
    test("booked.txt", "PAR", 150, "LON");

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
