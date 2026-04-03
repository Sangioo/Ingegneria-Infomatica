#include "../e2B.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct {
    char* paragraph;
    int result;
} ThreadArg;

void* calcolaFrasePiuLungaThread(void* arg) {
    ThreadArg* data = (ThreadArg*)arg;
    const char* text = data->paragraph;
    int max_len = 0, current_len = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        current_len++;
        if (text[i] == '.') {
            if (current_len > max_len)
                max_len = current_len;
            current_len = 0;
        }
    }

    data->result = max_len;
    return NULL;
}

void frasePiuLungaPerParagrafo(const char* nomefile, int* numeroParagrafi, int** lunghezzaFraseMaxPerParagrafo) {
    FILE* file = fopen(nomefile, "r");
    if (!file) {
        perror("Errore apertura file");
        *numeroParagrafi = 0;
        *lunghezzaFraseMaxPerParagrafo = NULL;
        return;
    }

    char buffer[MAX_PARAGRAPH_LEN];
    char* paragraphs[MAX_PARAGRAPHS];
    int count = 0;
    buffer[0] = '\0';

    // leggo il file riga per riga
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0) {
            if (strlen(buffer) > 0) {
                paragraphs[count] = strdup(buffer);
                count++;
                buffer[0] = '\0';
            }
        } else {
            strcat(buffer, line);
        }
    }

    if (strlen(buffer) > 0) {
        paragraphs[count] = strdup(buffer);
        count++;
    }

    fclose(file);

    pthread_t* threads = malloc(sizeof(pthread_t) * count);
    ThreadArg* args = malloc(sizeof(ThreadArg) * count);
    *lunghezzaFraseMaxPerParagrafo = malloc(sizeof(int) * count);
    *numeroParagrafi = count;

    // lancio dei thread
    for (int i = 0; i < count; i++) {
        args[i].paragraph = paragraphs[i];
        pthread_create(&threads[i], NULL, calcolaFrasePiuLungaThread, &args[i]);
    }

    // attesa dei thread
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
        (*lunghezzaFraseMaxPerParagrafo)[i] = args[i].result;
        free(paragraphs[i]);
    }

    free(threads);
    free(args);
}
