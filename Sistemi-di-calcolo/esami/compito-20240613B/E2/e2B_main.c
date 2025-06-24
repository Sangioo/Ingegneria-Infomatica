#include "e2B.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score, trials;
struct connessione * list;

struct connessione *creaNodo(const char * partenza, const char * dest, int costo) {
    struct connessione *new_node = (struct connessione *)malloc(sizeof(struct connessione));
    if (new_node != NULL) {
        strncpy(new_node->partenza, partenza, sizeof(new_node->partenza) - 1);
        new_node->partenza[sizeof(new_node->partenza) - 1] = '\0';
        strncpy(new_node->destinazione, dest, sizeof(new_node->destinazione) - 1);
        new_node->destinazione[sizeof(new_node->destinazione) - 1] = '\0';
        new_node->costo = costo;
        new_node->next = NULL;
    }
    return new_node;
}

// Funzione per aggiungere un nodo alla fine della lista collegata
void aggiungiNodo(struct connessione ** list, const char * part, const char * dest, int costo) {
    struct connessione * new_node = creaNodo(part, dest, costo);
    if (*list == NULL) {
        *list = new_node;
    } else {
        struct connessione * current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

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

void emptyList(struct connessione ** list) {
    struct connessione * current = *list;
    while (current != NULL) {
        struct connessione *next = current->next;
        free(current);
        current = next;
    }
    *list=NULL;
}

static void test(const char * file, const char * part, const int budget, const char * correct) {
    trials++;
    destinazioniAcquistabili(list, part, budget, file);
    char* out = convert2string(file);
    int ok = (out==NULL?-1:strcmp(correct, out)) == 0;
    if (out) free(out);
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    list = NULL;
    aggiungiNodo(&list,"ROM","VEN",250);
    aggiungiNodo(&list,"ROM","NYC",680);
    aggiungiNodo(&list,"ROM","MAD",400);
    aggiungiNodo(&list,"MIL","PAR",300);
    aggiungiNodo(&list,"ROM","PAR",350);
    aggiungiNodo(&list,"ROM","MIL",130);
    aggiungiNodo(&list,"MIL","ROM",135);
    aggiungiNodo(&list,"PAR","LON",110);
    aggiungiNodo(&list,"MIL","LON",300);
    aggiungiNodo(&list,"ROM","LON",410);

    test("out.txt", "ROM", 200, "ROM-MIL-130");
    test("out.txt", "BER", 600, "");
    test("out.txt", "ROM", 600, "ROM-MIL-130|ROM-VEN-250|ROM-PAR-350|ROM-MAD-400|ROM-LON-410");
    test("out.txt", "MIL", 800, "MIL-ROM-135|MIL-PAR-300|MIL-LON-300");
    test("out.txt", "MIL", 100, "");
    test("out.txt", "PAR", 150, "PAR-LON-110");

    printf("Risultato: %d/%d\n", score, trials);

    emptyList(&list);

    return EXIT_SUCCESS;
}
