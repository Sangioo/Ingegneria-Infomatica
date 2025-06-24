#include "e1.h"
#include <string.h>

int compare(const void *arg1, const void *arg2) {
    person_t a = *(person_t *)arg1;
    person_t b = *(person_t *)arg2;
    return strcmp(a.name, b.name);
}

void sort_people(person_t p[], size_t n) {
    qsort(p, n, sizeof(person_t), compare);
}

person_t *find_person(char *key, person_t sorted[], size_t n) {
    return (person_t *) bsearch(&key, sorted, n, sizeof(person_t), compare);
}