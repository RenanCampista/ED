#include "flist.h"
#include <stdlib.h>

Node *node_create(data_type value, Node *next) {
    Node *node = calloc(1, sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

void node_destroy(Node *node) {
    free(node);
}

Flist *flist_create() {
    return calloc(1, sizeof(Flist));
}

void flist_push_front(Flist *flist, data_type value) {
    Node *node = node_create(value, flist->head);
    flist->size++;
}

void flist_destroy(Flist *flist) {
    Node *node_it = flist->head;
    Node *new_next;

    while(node_it != NULL) {
        new_next = node_it->next;
        free(node_it);
        node_it = new_next;
    }
    free(node_it);
}

