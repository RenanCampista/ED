#include <stdlib.h>
#include <stdio.h>
#include "flist.h"

int main() {

    // Node *n3 = node_create(3, NULL);
    // Node *n2 = node_create(2, n3);
    // Node *n1 = node_create(1, n2);

    Node *head = NULL;

    for (int i = 10; i > 0; i--) {
        head = node_create(i, head);
    }

    Node *node_it = head;
    Node *new_next;

    while (head != NULL) {
        printf("%d ", head->value);
        node_it = node_it->next;
    }

    while(head != NULL) {
        new_next = node_it->next;
        free(node_it);
        node_it = new_next;
          
    }

    return 0;
}