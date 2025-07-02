#include "e3.h"
#include "stdio.h"

int getStudents(const char * filename, student * in_list, int min_mark) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) goto cleanup;

    while (in_list != NULL) {
        if (in_list->mark >= min_mark) {
            fprintf(f, "%s %s - %d\n", in_list->surname, in_list->name, in_list->mark);
        }

        in_list = in_list->next;
    }

    int res = fclose(f);
    if (res < 0) goto cleanup;
    return 0;

cleanup:
    if (f != NULL) fclose(f);
    return -1;
}