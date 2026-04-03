#include "../e2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_LINES     16     // 16 linee preallocate
#define MAX_LINE_SIZE 4096   // massima dimensione di una linea di testo nel file

static int add_line(char* line, char ***lines, int *num_lines, int *max_num_lines) {

    // ingrandisce l'array di linee se non c'è più spazio
    if (*num_lines >= *max_num_lines) {
        int i = *max_num_lines;
        *max_num_lines += *max_num_lines / 2;
        *lines = realloc(*lines, *max_num_lines * sizeof(char*));
        if (*lines == NULL) return -1;
        for (; i<*max_num_lines; ++i) (*lines)[i] = NULL;
    }

    (*lines)[*num_lines] = malloc(strlen(line)+1);
    if ((*lines)[*num_lines] == NULL) return -1;

    strcpy((*lines)[*num_lines], line); 

    *num_lines += 1;

    return 0;
}

void deallocate_lines(char **lines, int num_lines) {
    int i;
    for (i=0; i<num_lines; ++i)
        free(lines[i]);
    free(lines);
}

int read_file_by_line(const char *filename, char ***lines, int *num_lines) {
    
    char line[MAX_LINE_SIZE];
    FILE* fd = NULL;
    int max_num_lines = MAX_LINES;
    
    *lines = NULL;
    *num_lines = 0;
        
    fd = fopen(filename, "r");
    if (fd == NULL) goto cleanup;
    
    *lines = malloc(MAX_LINES*sizeof(char*));
    if (*lines == NULL) goto cleanup;

    for (;;) {
        char* out = fgets(line, MAX_LINE_SIZE, fd);
        if (out == NULL) {
            if (ferror(fd)) goto cleanup;
            break;
        }
        int len = strlen(line); 
        if (len > 0 && line[len-1]=='\n') line[len-1]='\0';
        int res = add_line(line, lines, num_lines, &max_num_lines);
        if (res != 0) goto cleanup;
    }
    
    fclose(fd);
    
    return 0;

cleanup: ;
    int curr_errno = errno;
    if (fd != NULL) fclose(fd);
    if (*lines != NULL) 
        deallocate_lines(*lines, *num_lines);
    errno = curr_errno;
}
