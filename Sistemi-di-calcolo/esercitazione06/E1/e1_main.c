#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e1.h"

int score, trials;

static void _print_vec(short buf[], int n);
static int _equal_list_array_rev(node_t *l, short buf[], int n);

void test(short buf[], int n) {
    trials++;

    node_t *l;

    int res = list_new_from_buffer(&l, buf, n);
    assert(res == 0);
    int ls = list_size(l);

    printf("Test %d: size: %d [corretto=%d]\n", trials, ls, n);
    printf(" -- Calcolato: ");
    list_print(l);
    printf(" -- Corretto:  ");
    _print_vec(buf, n);

    res = _equal_list_array_rev(l, buf, n);

    list_delete(&l);

    score += res == 0 && ls == n;
}

int main() {
    short b1[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    int n1 = sizeof(b1)/sizeof(short);

    short b2[] = { 26, -5, 1, -2, -7, -5, 9, 13, -9 };
    int n2 = sizeof(b2)/sizeof(short);

    short b3[] = {  };
    int n3 = sizeof(b3)/sizeof(short);

    test(b1, n1);
    test(b2, n2);

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

int lists_equal(node_t *l1, node_t *l2) {
    while (l1!=NULL && l2!=NULL) {
        if (l1->elem != l2->elem) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1==NULL && l2==NULL;
}

static void _print_vec(short buf[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ", buf[i]);
    printf("\n");
}

static int _equal_list_array_rev(node_t *l, short buf[], int n) {
    while ((--n >=0) &&  l != NULL) {
        if (l->elem != buf[n]) return 0;
        l = l->next;
        n--;
    }

    if (l!=NULL && n == -1 || l==NULL && n >= 0) return 0;

    return 1;
}
