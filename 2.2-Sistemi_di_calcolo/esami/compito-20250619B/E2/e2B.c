#include "e2B.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void * maxLen(void *t) {
    char *paragraph = (char *) t;
    paragraph[strlen(paragraph) - 1] = '\0';

    char *token = strtok(paragraph, ".");
    int max = 0, len;
    while (token) {
        len = strlen(token) + 1;
        if (len > max) max = len;
        token = strtok(NULL, ".");
    }
    
    return (void *) max;
}

void frasePiuLungaPerParagrafo(const char* nomefile, int* numeroParagrafi, int** lunghezzaFraseMaxPerParagrafo) {
    FILE* f = fopen(nomefile, "r");
    if (f == NULL) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }

    char *paragraphs[MAX_PARAGRAPHS], row[MAX_LINE_LEN], paragraph[MAX_PARAGRAPH_LEN];
    int lastRow = 0;
    *numeroParagrafi = 0;
    paragraph[0] = '\0';
    char *check = fgets(row, sizeof(row), f);
    while (check || lastRow) {
        if (strcmp(row, "\n") == 0) {
            paragraphs[*numeroParagrafi] = (char *) malloc(sizeof(char) * (strlen(paragraph) + 1));
            if (paragraphs[*numeroParagrafi] == NULL) {
                perror("[ERROR]");
                exit(EXIT_FAILURE);
            }

            memcpy(paragraphs[*numeroParagrafi], paragraph, sizeof(char) * (strlen(paragraph) + 1));
            (*numeroParagrafi)++;
            paragraph[0] = '\0';

            if (lastRow) break;
        } else {
            strcat(paragraph, row);
        }

        check = fgets(row, sizeof(row), f);
        if (!check) {
            lastRow = 1;
            strcpy(row, "\n");
        }
    }

    *lunghezzaFraseMaxPerParagrafo = (int *) malloc(sizeof(int) * *numeroParagrafi);
    if (*lunghezzaFraseMaxPerParagrafo == NULL) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }

    int res;
    pthread_t threads[*numeroParagrafi];
    for (int i = 0; i < *numeroParagrafi; i++) {
        res = pthread_create(&(threads[i]), NULL, maxLen, (void *) paragraphs[i]);
        if (res != 0) {
            perror("[ERROR]");
            exit(EXIT_FAILURE);
        }
    }

    int len;
    for (int i = 0; i < *numeroParagrafi; i++) {
        res = pthread_join(threads[i], (void **)(&len));
        if (res != 0) {
            perror("[ERROR]");
            exit(EXIT_FAILURE);
        }
        (*lunghezzaFraseMaxPerParagrafo)[i] = len;
    }

    res = fclose(f);
    if (res < 0) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }
}