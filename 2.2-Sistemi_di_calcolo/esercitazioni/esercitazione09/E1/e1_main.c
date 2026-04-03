#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "e1.h"

int score, trials;

static char * getOutput(person_t* list) {
    char* out = strdup("");
    while(list!=NULL) {
        int size = strlen(out) + strlen(list->surname);
        char * tmp = malloc((size + 1) * sizeof(char));
        strcpy(tmp, out);
        strcat(tmp, list->surname);
        free(out);
        out = tmp;
        list = list->next;
        // printf("out: %s\n", out);
    }
    return out;
}

static void test(const char* file, int minYear, const char * correct) {
    trials++;
    struct person_t * list;
    int res = parseCSV(file, &list, minYear);
    int ok;
    if (correct == NULL)
        ok = res == -1 && list == NULL ? 1 : 0;
    else if (res != 0)
        ok = 0;
    else {
        char* result = getOutput(list);
        // printf("result: %s\n", result);
        ok = strcmp(correct, result) == 0;
        free(result);
    }
    
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {

    test("nonesiste.csv", 20, NULL);
    test("a.csv", 0, "");
    test("b.csv", 1970, "HofstadterCooperTellerWolowitzFowlerBloom");
    test("b.csv", 1984, "Teller");
    
    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
