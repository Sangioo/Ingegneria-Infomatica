#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*** NON MODIFICARE PER NESSUNO MOTIVO IL CODICE CHE SEGUE ***/

int score, trials;

long fileSize(FILE *file) {
    long currentPos = ftell(file);
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, currentPos, SEEK_SET);
    return size;
}

char *convert2string(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return NULL;
    }

    // Calcola la dimensione totale approssimativa del file per l'allocazione iniziale
    long size = fileSize(file);

    // Alloca la memoria per il contenuto del file più i separatori '|'
    char *result = (char *)malloc(size * sizeof(char) + 1); // +1 per il terminatore null
    if (result == NULL) {
        perror("Errore nell'allocazione della memoria");
        fclose(file);
        return NULL;
    }

    result[0] = '\0'; // Assicurati che la stringa sia vuota all'inizio

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Rimuovi il carattere di nuova linea dalla fine della riga
        line[strcspn(line, "\n")] = '\0';
        // Aggiungi la riga alla stringa risultante
        strcat(result, line);
        // Aggiungi il separatore '|'
        strcat(result, "|");
    }

    // Rimuovi l'ultimo separatore '|'
    if (strlen(result) > 0) {
        result[strlen(result) - 1] = '\0';
    }

    fclose(file);
    return result;
}

static void test(const char * sourcefile, const char * destfile, const char * prefix, const char * correct, const int numCorrect) {
    trials++;
    int num = cercaEdEsporta(sourcefile, prefix, destfile);
    int ok = 1;
    if (num != numCorrect) {
        ok = 0;
        printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
        return;
    }
    else {
        char* out = convert2string(destfile);
        int ok = (out==NULL?-1:strcmp(correct, out)) == 0;
        if (out) free(out);
        printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
        score += ok;
    }
}


int main() {

    test("contatti1.txt", "result.csv", "Mario", "Mario Rossi,+393297854258",5);
    test("contatti1.txt", "result.csv", "Mar", "Martina Bianchini,+398452158|Mario Rossi,+393297854258",4);
    test("contatti1.txt", "result.csv", "Leo", "",6);
    test("contatti1.txt", "result.csv", "", "Francesco Massimo Ernesti Pidu,00390872897551|Giovanni Bizantini,3859647851|Martina Bianchini,+398452158|Massimo Cielesti,0015065284785|Elisa Verdi,+398569574|Mario Rossi,+393297854258",0);
    test("contatti1.txt", "result.csv", "Francesco", "Francesco Massimo Ernesti Pidu,00390872897551",5);

    printf("Punteggio: %d/%d\n", score, trials);    

    return EXIT_SUCCESS;

}
