#include "e2C.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

static void test(const char * sourcefile, const char * destfile, const char * part, const int budget, const char * correct) {
    trials++;
    destinazioniSottoBudget(sourcefile, part, budget, destfile);
    char* out = convert2string(destfile);
    int ok = (out==NULL?-1:strcmp(correct, out)) == 0;
    if (out) free(out);
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    test("booked.txt", "out.txt", "ROM", 200, "ROM-MIL-130");
    test("booked.txt", "out.txt", "BER", 600, "");
    test("booked.txt", "out.txt", "ROM", 600, "ROM-MIL-130|ROM-VEN-250|ROM-PAR-350|ROM-MAD-400|ROM-LON-410");
    test("booked.txt", "out.txt", "MIL", 800, "MIL-ROM-135|MIL-PAR-300|MIL-LON-300");
    test("booked.txt", "out.txt", "MIL", 100, "");
    test("booked.txt", "out.txt", "PAR", 150, "PAR-LON-110");

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
