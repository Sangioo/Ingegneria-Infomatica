#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char id[16];
    char value[16];
    struct node * next;
} node_t;

static int count = 0;

node_t* add_node(node_t* l, char* value) {
    node_t* node = malloc(sizeof(node_t));

    sprintf(node->id, "ID_%d", count++);
    strcpy(node->value, value);

    if (l != NULL)
        node->next = l;

    return node;
}

void print_list(node_t* head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%s\n", current->value);
        current = current->next;
    }
}

void delete_list(node_t * head) {
    node_t* current = head, *tmp = NULL;

    while (current != NULL) {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}

int main() {
    node_t* l;

    l = add_node(NULL, "Hello");
    l = add_node(l, " ");
    l = add_node(l, "World");
    l = add_node(l, "!");

    print_list(l);
    delete_list(l);

    printf("Risultato 1/1\n");
    return 0;
}
