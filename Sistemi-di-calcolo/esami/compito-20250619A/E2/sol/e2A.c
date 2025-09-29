#include "../e2A.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

int contaFrasi(const char* testo) {
    int count = 0;
    while (*testo) {
        if (*testo == '.')
            count++;
        testo++;
    }
    return count;
}

void numeroFrasiMaxParagrafi(const char* filename, int* maxNumeroFrasi) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Errore apertura file");
        exit(EXIT_FAILURE);
    }

    char* paragrafi[MAX_PARAGRAFI];
    int numParagrafi = 0;
    char buffer[MAX_PARAGRAFO_LEN];
    char paragrafo[MAX_PARAGRAFO_LEN] = "";

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strcmp(buffer, "\n") == 0) {
            if (strlen(paragrafo) > 0) {
                paragrafi[numParagrafi] = malloc(strlen(paragrafo) + 1);
                if (!paragrafi[numParagrafi]) {
                    perror("malloc fallita");
                    exit(EXIT_FAILURE);
                }
                strcpy(paragrafi[numParagrafi], paragrafo);
                numParagrafi++;
                paragrafo[0] = '\0';
            }
        } else {
            strcat(paragrafo, buffer);
        }
    }

    // Aggiungi l'ultimo paragrafo se non termina con newline
    if (strlen(paragrafo) > 0) {
        paragrafi[numParagrafi] = malloc(strlen(paragrafo) + 1);
        if (!paragrafi[numParagrafi]) {
            perror("malloc fallita");
            exit(EXIT_FAILURE);
        }
        strcpy(paragrafi[numParagrafi], paragrafo);
        numParagrafi++;
    }

    fclose(file);

    *maxNumeroFrasi = 0;

    for (int i = 0; i < numParagrafi; i++) {
        pid_t pid = fork();
        if (pid == 0) {           
            int frasi = contaFrasi(paragrafi[i]);
            if (frasi > 255) frasi = 255; // Limitazione dello status code
            
            // pulizia della memoria nei figli
            for (int i = 0; i < numParagrafi; i++) {
                free(paragrafi[i]);
            }

            exit(frasi);
        } else if (pid < 0) {
            perror("fork fallita");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < numParagrafi; i++) {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            int risultato = WEXITSTATUS(status);
            if (risultato > *maxNumeroFrasi) {
                *maxNumeroFrasi = risultato;
            }
        }
    }

    // pulizia della memoria nel processo padre
    for (int i = 0; i < numParagrafi; i++) {
        free(paragrafi[i]);
    }
}