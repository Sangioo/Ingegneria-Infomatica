#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void getData(char* riga, char** nome, char** numero) {
    int len = 0;
    char* riga_tmp = riga;
    while (*riga_tmp != '\0' && *riga_tmp != '_' && len < 30) {
        len++;
        riga_tmp++;
    }
    
    *nome = (char *) calloc(len + 1, sizeof(char));
    strncpy(*nome, riga, len);
    
    len = 0;
    riga_tmp = riga + 30;
    while (*riga_tmp != '\0' && *riga_tmp != '_' && len < 14) {
        len++;
        riga_tmp++;
    }
    
    *numero = (char *) calloc(len + 1, sizeof(char));
    strncpy(*numero, riga + 30, len);
}

int insertFirst(FILE* f, char* nome, char* numero) {
    int res = fseek(f, 0, SEEK_END);
    if (res < 0) return -1;

    int size = ftell(f);
    if (size < 0) return -1;

    res = fseek(f, 0, SEEK_SET);
    if (res < 0) return -1;

    if (size == 0) {
        res = fprintf(f, "%s,%s\n", nome, numero);
        if (res < strlen(nome)+strlen(numero)+2) return -1;

        return 0;
    } else {
        char* buff = (char *) malloc(size);
        if (buff == NULL) return -1;

        fread(buff, 1, size, f);

        res = fseek(f, 0, SEEK_SET);
        if (res < 0) {
            free(buff);
            return -1;
        }

        fprintf(f, "%s,%s\n", nome, numero);
        fwrite(buff, 1, size, f);

        return 0;
    }
}

int cercaEdEsporta(const char * filenameSource, const char * prefix, const char * filenameDest) {
    // apro il file di input
    FILE* fin = fopen(filenameSource, "r");
    if (fin == NULL) goto cleanup;

    // apro il file di output
    FILE* fout = fopen(filenameDest, "w+");
    if (fout == NULL) goto cleanup;

    char riga[46], nome_pad[31], numero_pad[15];
    char *nome;
    char *numero;
    int num = 0, res;

    while (fgets(riga, 46, fin) != NULL) {
        getData(riga, &nome, &numero);
        
        if (strncmp(nome, prefix, strlen(prefix)) == 0) {
            res = insertFirst(fout, nome, numero);
            if (res < 0) goto cleanup;
        } else {
            num++;
        }

        free(nome);
        free(numero);
    }

    // chiudo i file
    int out = fclose(fin);
    if (out < 0) goto cleanup;
    out = fclose(fout);
    if (out < 0) goto cleanup;

    return num;

cleanup:
    int curr_errno = errno;
    perror("[ERROR]");

    if (fin != NULL) fclose(fin);
    if (fout != NULL) fclose(fout);

    errno = curr_errno;
    return -1;
}