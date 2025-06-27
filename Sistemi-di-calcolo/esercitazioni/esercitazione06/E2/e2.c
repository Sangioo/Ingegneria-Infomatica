#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2) {
    while (l1!=NULL && l2!=NULL) {
        if (l1->elem != l2->elem) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1==NULL && l2==NULL;
}
