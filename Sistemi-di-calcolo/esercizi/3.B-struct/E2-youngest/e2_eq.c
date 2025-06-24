#include <stdlib.h>
#include "e2.h"

person_t *find_youngest(person_t *v, int n) {
    person_t *a = NULL;
    int c = 0;
    person_t* b = v;
L:
    if(c>=n) goto E;
    if (a==NULL) goto A;
    char dl = v[c].age; 
    if (b[c].age >= a->age) goto A2;
A:
    a = &b[c];
A2:
    ++c;
    goto L;
E:
    return a;
}
