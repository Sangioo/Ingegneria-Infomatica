#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2) {
    const node_t* c = l1;
    const node_t* d = l2;

L:
    if (c == 0) goto F;
    if (d == 0) goto F;

    short a = (*d).elem;
    if ((*c).elem == a) goto E;
    return 0;
E:
    c = (*c).next;
    d = (*d).next;
    goto L;
F:
    char al = c == 0;
    char ah = d == 0;
    al = al & ah;
    return (int) al;
}