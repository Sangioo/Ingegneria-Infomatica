#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e2.h"

int score, trials;

void test(short* b1, int n1, short* b2, int n2, int sol) {
    trials++;

    node_t *l1;
    node_t *l2;

    int r1 = list_new_from_buffer(&l1, b1, n1);
    assert(r1 == 0);

    int r2 = list_new_from_buffer(&l2, b2, n2);
    assert(r2 == 0);

    int res = list_equal(l1,l2);

    printf("Test %d: risultato=%d [corretto=%d]\n", trials, res, sol);
    list_delete(&l1);
    list_delete(&l2);

    score += res == sol;
}

int main() {
    short b1[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    int n1 = sizeof(b1)/sizeof(short);

    short b2[] = { 26, -5, 1, -2, -7, -5, 9, 13, -9 };
    int n2 = sizeof(b2)/sizeof(short);

    short b3[] = {  };
    int n3 = sizeof(b3)/sizeof(short);

    test(b1, n1, b2, n2, 0);
    test(b1, n1, b1, n1, 1);
    test(b2, n2, b2, n2, 1);
    test(b2, n2, b3, n3, 0);

    printf("Risultato: %d/%d\n", score, trials);
    return 0;
}


// list implementation

void list_new(node_t **l) {
    *l = NULL;
}

// returns
int list_new_from_buffer(node_t **l, short* buf, int n){
    *l = NULL;
    while (--n >= 0)
        if (list_add_first(l, buf[n])) return -1;
    return 0;
}

void list_delete(node_t **l) {
    node_t *p = *l;
    while (p != NULL) {
        node_t *dead = p;
        p = p->next;
        free(dead);
    }
    *l = NULL;
}

int list_size(const node_t *p) {
    int s = 0;
    for (; p!=NULL; p=p->next)
        s++;
    return s;
}

void list_print(const node_t *p) {
    int s = 0;
    for (; p!=NULL; p=p->next)
        printf("%d ", p->elem);
    printf("\n");
}

int list_sum(const node_t *p) {
    int s = 0;
    for (; p!=NULL; p=p->next)
        s += p->elem;
    return s;
}

int list_add_first(node_t **l, short elem) {
    node_t *p = *l;
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL) return -1;           // allocation error
    n->elem = elem;
    n->next = p;
    *l = n;
    return 0;
}

