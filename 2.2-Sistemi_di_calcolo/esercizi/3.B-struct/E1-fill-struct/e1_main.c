#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e1.h"

int main() {
    person_t *p = malloc(sizeof(person_t));
    assert(p!=NULL);
    printf("sizeof(person_t): %ld\n", (unsigned long)sizeof(person_t));
    fill(p, 20, "Grace Hopper", 'F');
    printf("age: %d - name: %s - gender: %c\n", p->age, p->name, p->gender);
    free(p);
    return 0;
}
