#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getBooking(char* buff, char* giorno, char* orario, char* durata) {
    strncpy(giorno, buff + 30, 10);
    giorno[10] = '\0';
    strncpy(orario, buff + 40, 5);
    orario[5] = '\0';
    strncpy(durata, buff + 45, 3);
    durata[3] = '\0';
}

int getFirstEmptySlot(const char * filename, int len, char ** output) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    *output = (char *) malloc(sizeof(char)*17);
    if (*output == NULL) goto cleanup;

    char riga[50];
    int res;
    char giorno_curr[11], orario_curr[6], durata_curr[4];
    char giorno_tmp[11], orario_tmp[6], durata_tmp[4];
    orario_tmp[5] = '\0';
    durata_tmp[3] = '\0';

    if (fgets(riga, sizeof(riga), f) != NULL) {
        getBooking(riga, giorno_curr, orario_curr, durata_curr);
    }
    
    // ciclo per ogni giorno possibile
    unsigned trovato;
    for (int i = 18; i <= 22; i++) {
        strncpy(orario_tmp, "08:00", 5);
        res = sprintf(giorno_tmp, "%02d/09/2023", i);
        if (res != 10) goto cleanup;

        trovato = 0;
        while (strcmp(giorno_curr, giorno_tmp) == 0) {
            if (calculateTimeDifference(orario_tmp, orario_curr) >= len) {
                res = sprintf(*output, "%s %s", giorno_tmp, orario_tmp);
                if (res != 16) goto cleanup;
                trovato = 1;
                break;
            }
            char* tmp = addMinutesToTime(orario_curr, atoi(durata_curr));
            strcpy(orario_tmp, tmp);
            free(tmp);

            if (fgets(riga, sizeof(riga), f) != NULL) {
                getBooking(riga, giorno_curr, orario_curr, durata_curr);
            } else {
                break;
            }
        }

        if (trovato == 1) break;

        if (calculateTimeDifference(orario_tmp, "18:00") >= len) {
            res = sprintf(*output, "%s %s", giorno_tmp, orario_tmp);
            if (res != 16) goto cleanup;
            trovato = 1;
            break;
        }
    }
    return (trovato == 1) ? 0 : -1;
cleanup:
    if (f != NULL) fclose(f);
    if (*output != NULL) free(*output);
    return -1;
}