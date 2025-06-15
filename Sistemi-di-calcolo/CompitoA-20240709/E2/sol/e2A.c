#include "../e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int posizioneInizioPadding(const char* data, int firstPos, int lastPos) {
    char charPadding = '_';
    int i, j = lastPos;
    for (i = firstPos; i < lastPos; i++) {
        if (data[i] == charPadding) {
            j = i; 
            break;
        }
    }
    return j;
} 

int cerca(const char * filename, const char * prefix, struct contatto ** arrayMatches) {
    
    FILE* fp;

    // Apro il file
	fp = fopen(filename, "r");
	if (fp == NULL) 
        return -1;

    // Variabili di appoggio
    struct contatto *temp_contatti[32];
    int risultati_trovati = 0, pos = 0;
    char nome_corrente [32];

    // buffer riga
    char buf[48]; // 46 byte dati +  '\n' + '\0' aggiunto da fgets
	char * ret = fgets(buf, sizeof(buf), fp);
	while (ret != NULL) {
        memcpy(nome_corrente, buf, 31); // copia caratteri nome
        nome_corrente[strlen(prefix)] = '\0'; // termina la copia del nome alla lunghezza del prefisso
        if (strcmp(nome_corrente,prefix)==0) { // confronta prefisso e nome abbreviato
            struct contatto *temp_cont = (struct contatto *)malloc(sizeof(struct contatto));
            if (temp_cont == NULL)
                exit(EXIT_FAILURE);
            pos = posizioneInizioPadding(ret, 0, 31);
            memcpy(temp_cont->nomecompleto, buf, pos);
            temp_cont->nomecompleto[pos] = '\0';
            pos = posizioneInizioPadding(ret, 31, 46);
            memcpy(temp_cont->numero, buf + 31, pos-31);
            temp_cont->numero[pos-31] = '\0';
            temp_contatti[risultati_trovati] = temp_cont;
            risultati_trovati++;
        }
        ret = fgets(buf, sizeof(buf), fp);
    }

    fclose(fp);

    struct contatto *contatti_match = malloc(sizeof(struct contatto)*risultati_trovati);
    for (int i = 0; i<risultati_trovati; i++) {
        memcpy(&contatti_match[i], temp_contatti[i], sizeof(struct contatto));
        free(temp_contatti[i]);
    }
    *arrayMatches = contatti_match;
    return risultati_trovati;

}