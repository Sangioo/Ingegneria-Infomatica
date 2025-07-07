#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_ENTRY 37
#define LEN_SURNAME 30
#define LEN_PLACES 2
#define LEN_TIME 5

void getData(char * entry, char ** surname, int * places, char ** time) {
    char *tmp = entry;
    int len = 0;
    while (*tmp != '_' && *tmp != '\0') {
        len++;
        tmp++;
    }
    *surname = (char *) malloc(sizeof(char) * (len + 1));
    (*surname)[len] = '\0';
    strncpy(*surname, entry, len);

    char p[LEN_PLACES + 1] = { entry[LEN_SURNAME], entry[LEN_SURNAME + 1], '\0' };
    *places = atoi(p);

    *time = (char *) malloc(sizeof(char) * (LEN_TIME + 1));
    (*time)[LEN_TIME] = '\0';
    strncpy(*time, entry + LEN_SURNAME + LEN_PLACES, LEN_TIME);
}

void getBookingsAfterTime(struct booking ** list, const char * filename, const char * time) {
    FILE* f = fopen(filename, "r");

    struct booking *head = NULL, *tail = NULL, *curr = NULL;
    char entry[LEN_ENTRY + 1];
    entry[LEN_ENTRY] = '\0';

    while (fgets(entry, sizeof(entry), f) != NULL) {
        printf("[%s]\n", entry);
        if (strncmp(time, entry + LEN_SURNAME + LEN_PLACES, LEN_TIME) > 0) continue;

        curr = (struct booking *) malloc(sizeof(struct booking));
        getData(entry, &(curr->surname), &(curr->places), &(curr->time));
        curr->next = NULL;
        if (head == NULL) {
            head = curr;
            tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
    }
    *list = head;
    
    fclose(f);
}