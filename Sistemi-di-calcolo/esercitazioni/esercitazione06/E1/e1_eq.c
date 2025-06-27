#include <stdlib.h>
#include "e1.h"

int list_add_first(node_t **l, short elem) {
    node_t** si = l;
    node_t *b = *si;

    node_t* a = malloc(sizeof(node_t));

    if(a != NULL) goto F;
    return -1;
F:
    short d = elem;
    (*a).elem = d;
    (*a).next = b;
    *si = a;
    return 0;
}