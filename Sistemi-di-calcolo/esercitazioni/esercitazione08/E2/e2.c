#include "e2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *getSurname(const char* data) {
    int size = 0, j = 0;
    while (*(data + j) != '_' && *(data + j) != '\0') {
        size++;
        j++;
    }

    char *surname = (char *)malloc(size + 1);
    
    for (int i = 0; i < size; i++) {
        *(surname + i) = *(data + i);
    }
    *(surname + size) = '\0';

    return surname;
}

int getPlaces(const char* data) {
    int size = 2;
    char *places = (char *) malloc(size + 1);

    for (int i = 0; i < size; i++) {
        *(places + i) = *(data + i);
    }
    *(places + size) = '\0';

    int ret = atoi(places);
    free(places);

    return ret;
}

char *getTime(const char* data) {
    int size = 5;
    char *time = (char *) malloc(size + 1);

    for (int i = 0; i < size; i++) {
        *(time + i) = *(data + i);
    }
    *(time + size) = '\0';

    return time;
}

struct booking* getBookings_aux(const char * data, int size, const char * time) {
    if (*data == '\0') {
        return NULL;
    } 
    
    char *timep = getTime(data + 32);
    if (strcmp(time, timep) <= 0) {
        struct booking* prenotazione = (struct booking *) malloc(sizeof(struct booking));

        prenotazione->surname = getSurname(data);
        prenotazione->places = getPlaces(data + 30);
        prenotazione->time = timep;
        prenotazione->next = getBookings_aux(data + 37, size, time);
        return prenotazione;
    } else {
        return getBookings_aux(data + 37, size, time);
    }
}

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time) {
    *list = getBookings_aux(data, size, time);
}