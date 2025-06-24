#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e2.h"

person_t *find_youngest(person_t *v, int n);

int main() {

    person_t v[5] = { {'M', "Niels Bohr",     24},
                      {'M', "Nikola Tesla",   27},
                      {'F', "Marie Curie",    23},
                      {'M', "Michael Faraday", 24},
                      {'M', "Albert Einstein", 31}
                    };

    person_t *p = find_youngest(v,5);

    printf("sizeof(v): %ld\n", (unsigned long)sizeof(person_t));
    printf("age: %d - name: %s - gender: %c\n", p->age, p->name, p->gender);

    return 0;
}
