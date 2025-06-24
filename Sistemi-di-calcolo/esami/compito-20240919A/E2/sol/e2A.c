#include "../e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contatto {
    char nomecompleto[31]; 
    char numero[15];
};


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

int cercaEdEsporta(const char * filenameSource, const char * prefix, const char * filenameDest){
    
    FILE* fp; 
    FILE* fpout;

    // Apro il file
	fp = fopen(filenameSource, "r");
	if (fp == NULL) 
        return -1;

    fpout = fopen(filenameDest, "w");
    if (fpout == NULL) 
        return -1;

    // Variabili di appoggio
    int risultati_scartati = 0, pos = 0, risultati_trovati = 0;
    char nome_corrente [31];
    char numero_corrente [15];
    struct contatto *temp_contatti[32];

    // buffer riga
    char buf[46]; // 44 byte dati +  '\n' + '\0' aggiunto da fgets
	char * ret = fgets(buf, sizeof(buf), fp);
	while (ret != NULL) {
        memcpy(nome_corrente, buf, 30); // copia caratteri nome
        nome_corrente[strlen(prefix)] = '\0'; // termina la copia del nome alla lunghezza del prefisso
        if (strcmp(nome_corrente,prefix)==0) { // confronta prefisso e nome abbreviato
            pos = posizioneInizioPadding(ret, 0, 30);
            memcpy(nome_corrente, buf, pos);
            nome_corrente[pos] = '\0';
            pos = posizioneInizioPadding(ret, 30, 44);
            memcpy(numero_corrente, buf + 30, pos-30);
            numero_corrente[pos-30] = '\0';
            struct contatto *temp_cont = (struct contatto *)malloc(sizeof(struct contatto));
            strcpy(temp_cont->nomecompleto, nome_corrente);
            strcpy(temp_cont->numero, numero_corrente);
            temp_contatti[risultati_trovati] = temp_cont;
            risultati_trovati++;
        }
        else
            risultati_scartati++;
        ret = fgets(buf, sizeof(buf), fp);
    }

    for (int i = risultati_trovati-1; i>=0; i--) {
        fprintf(fpout,"%s,%s\n",temp_contatti[i]->nomecompleto,temp_contatti[i]->numero);
        free(temp_contatti[i]);
    }

    fclose(fp);
    fclose(fpout); 
    return risultati_scartati;   

}