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

