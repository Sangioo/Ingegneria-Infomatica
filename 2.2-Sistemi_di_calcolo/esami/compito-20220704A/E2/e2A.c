#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_ENTRY 37
#define LEN_SURNAME 30
#define LEN_PLACES 2
#define LEN_TIME 5

int getData(char * entry, char ** surname, int * places, char ** time) {
    char *tmp = entry;
    int len = 0;
    while (*tmp != '_' && *tmp != '\0') {
        len++;
        tmp++;
    }
    *surname = (char *) malloc(sizeof(char) * (len + 1));
    if (*surname == NULL) goto clean;

    (*surname)[len] = '\0';
    strncpy(*surname, entry, len);

    char p[LEN_PLACES + 1] = { entry[LEN_SURNAME], entry[LEN_SURNAME + 1], '\0' };
    *places = atoi(p);

    *time = (char *) malloc(sizeof(char) * (LEN_TIME + 1));
    if (*time == NULL) goto clean;

    (*time)[LEN_TIME] = '\0';
    strncpy(*time, entry + LEN_SURNAME + LEN_PLACES, LEN_TIME);

    return EXIT_SUCCESS;

clean:
    if (*surname != NULL) free(*surname);
    if (*time != NULL) free(*time);
    return EXIT_FAILURE;
}

void getLargeTables(struct booking ** list, const char * filename, int num) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    struct booking *head = NULL, *tail = NULL, *curr = NULL;
    char entry[LEN_ENTRY + 1], p[LEN_PLACES + 1];
    entry[LEN_ENTRY] = '\0';
    p[LEN_PLACES] = '\0';
    int res;

    while (fgets(entry, sizeof(entry), f) != NULL) {
        p[0] = entry[LEN_SURNAME];
        p[1] = entry[LEN_SURNAME + 1];
        if (atoi(p) < num) continue;

        curr = (struct booking *) malloc(sizeof(struct booking));
        if (curr == NULL) goto cleanup;

        res = getData(entry, &(curr->surname), &(curr->places), &(curr->time));
        if (res == EXIT_FAILURE) goto cleanup;
        
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

    res = fclose(f);
    if (res < 0) goto cleanup;
    return;

cleanup:
    if (f != NULL) fclose(f);
    if (head != NULL) {
        while (head != NULL) {
            struct booking *t = head->next;
            free(head);
            head = t;
        }
    }
    return;
}