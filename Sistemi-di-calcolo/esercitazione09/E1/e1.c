#include "e1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int parseCSV(const char* file, person_t** out, int minAge) {
    FILE *f = fopen(file, "r");
    if (f == NULL) goto cleanup;

    char row[64];
    int curr_year = 2025;
    person_t *head = NULL, *tail = NULL;
    while (fgets(row, sizeof(row), f)) {
        // se la riga e' vuota andiamo avanti
        if (strlen(row) == 0) continue;

        // tokenizzazione della stringa
        char *name_temp = strtok(row, ",");
        char *surname_temp = strtok(NULL, ",");
        char *date_temp = strtok(NULL, ",");
        char *phd_temp = strtok(NULL, ",");

        // se l'anno e' minore di quello minimo andiamo avanti
        int year = atoi(date_temp + 6);
        if (year < minAge) {
            continue;
        }
        
        // creazione del nodo
        person_t *person = (person_t *) malloc(sizeof(person_t));
        if (person == NULL) goto cleanup;

        // assegnazione del nome
        person->name = (char *) malloc(strlen(name_temp) + 1);
        if (person->name == NULL) goto cleanup;

        strcpy(person->name, name_temp);

        // assegnazione del cognome
        person->surname = (char *) malloc(strlen(surname_temp) + 1);
        if (person->surname == NULL) goto cleanup;

        strcpy(person->surname, surname_temp);

        // assegnazione dell'year
        person->year = year;

        // assegnazione del phd
        size_t len = strlen(phd_temp);
        if (len > 0 && phd_temp[len - 1] == '\n') {
            phd_temp[len - 1] = '\0';
        }
        person->has_phd = strcmp(phd_temp, "yes") == 0 ? 1 : 0;
        
        // assegnazione dell next
        person->next = NULL;

        // se e' il primo nodo aggiorniamo head, tail e *out, altrimenti solo tail
        if (head == NULL) {
            head = person;
            tail = person;
            *out = person;
        } else {
            tail->next = person;
            tail = person;
        }
    }

    // good ending
    fclose(f);
    return 0;

cleanup:
    // bad ending
    if (f == NULL) {
        *out = NULL;
    } else {
        fclose(f);
    }
    return -1;
}