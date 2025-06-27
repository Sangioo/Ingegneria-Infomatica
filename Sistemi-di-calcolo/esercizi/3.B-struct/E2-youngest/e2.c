#include <stdlib.h>
#include "e2.h"

person_t *find_youngest(person_t *v, int n) {
    person_t *y = NULL;
    int i;
    for (i=0; i<n; ++i)
        if (y==NULL || v[i].age < y->age)
            y = &v[i];
    return y;
}
