#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multi_get_env(const char** names, char*** values, int num) {
    *values = (char **) malloc(sizeof(char *) * num);
    if (*values == NULL) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }

    char *env = NULL;
    for (int i = 0; i < num; i++) {
        env = getenv(names[i]);
        if (env) {
            (*values)[i] = (char *) malloc(sizeof(char) * (strlen(env) + 1));
            if ((*values)[i] == NULL) {
                perror("[ERROR]");
                exit(EXIT_FAILURE);
            }
            memcpy((*values)[i], env, sizeof(char) * (strlen(env) + 1));
        } else {
            (*values)[i] = NULL;
            continue;
        }
    }
}
