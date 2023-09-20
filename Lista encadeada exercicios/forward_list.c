#include <stdio.h>
#include <stdlib.h>
#include "forward_list.h"

/**
 * @brief Construct a new Linked List:: Linked List object
 *  Allocates memory for a new linked list and returns a pointer to it.
 * @return ForwardList*
 * Pointer to the newly allocated linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the linked list using forward_list_destroy().
 *
 */
ForwardList *forward_list_construct() {
    ForwardList *l = (ForwardList *)malloc(sizeof(ForwardList));
    l->head = NULL;
    l->size = 0;
    return l;
}

/**
 * @brief Returns the size of the linked list.
 *  Returns the number of nodes in the linked list.
 * @param l
 * Pointer to the linked list.
 * @return int
 * Number of nodes in the linked list.
 *
 */
int forward_list_size(ForwardList *l){
    return l->size;
}

/**
 * @brief Pushes a new node to the front of the linked list.
 *  Allocates memory for a new node and inserts it at the front of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param data
 * Pointer to the data to be stored in the new node.
 *
 */
void forward_list_push_front(ForwardList *l, data_type data) {
    Node *n = node_construct(data, l->head);
    l->head = n;
    l->size++;
}

/**
 * @brief Print the elements of the linked list.
 *  Print the elements of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 *
 */
void forward_list_print(ForwardList *l, void (*print_fn)(data_type)) {
    Node *n = l->head;
    printf("[");
    while (n != NULL) {
        print_fn(n->value);
        n = n->next;
        if (n != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

/**
 * @brief Returns the data stored in the node at the given index.
 * @param l
 * Pointer to the linked list.
 * @param i
 * Index of the node.
 * @return data_type
 * Data stored in the node at the given index.
 *
 */
data_type forward_list_get(ForwardList *l, int i) {
    Node *n = l->head;
    int cont = 0;
    while (n != NULL) {
        if (cont == i) { 
            break;
        }
        n = n->next;
        cont++;
    }
    return n->value;
}

/**
 * @brief Remove the first node of the linked list and returns its data.
 * @param l
 * Pointer to the linked list.
 * @return data_type
 * Pointer to the data stored in the first node of the linked list that was removed.
 *
 */
data_type forward_list_pop_front(ForwardList *l) {
    Node *n = l->head;
    data_type data = n->value;
    l->head = n->next;
    node_destroy(n);
    l->size--;
    return data;
}

/**
 * @brief Create a new list given by the reverse of the given list.
 * @param l
 * Pointer to the linked list.
 * @return ForwardList*
 * Pointer to the newly allocated linked list.
 */
ForwardList *forward_list_reverse(ForwardList *l) {
    ForwardList *m = forward_list_construct();
    Node *n = l->head;
    while (n != NULL) {
        forward_list_push_front(m, n->value);
        n = n->next;
    }
    return m;
}

/**
 * @brief Removes all nodes from the linked list.
 * Removes all nodes from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the data stored in the nodes.
 */
void forward_list_clear(ForwardList *l);

/**
 * @brief Removes all nodes with the given value from the linked list.
 * Removes all nodes with the given value from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @param val
 * Value to be removed from the linked list.
 */
void forward_list_remove(ForwardList *l, data_type val) {
    // Node *n = l->head;
    // Node *prev = NULL;
    // while (n != NULL) {
    //     if (n->value == val) {
    //         if (prev == NULL) {
    //             l->head = n->next;
    //         } else {
    //             prev->next = n->next;
    //         }
    //         Node *next = n->next;
    //         node_destroy(n);
    //         n = next;
    //         l->size--;
    //     } else {
    //         prev = n;
    //         n = n->next;
    //     }
    // }
}

/**
 * @brief Removes all duplicate values from the linked list.
 * Removes all duplicate values from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @note
 * The linked list must be sorted.
 */
void forward_list_unique(ForwardList *l);

/**
 * @brief Adds all nodes from the given list to the end of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param m
 * Pointer to the linked list to be added to the end of the linked list.
 */
void forward_list_cat(ForwardList *l, ForwardList *m);

/**
 * @brief Sorts the linked list.
 * Sorts the linked list.
 * @param l
 * Pointer to the linked list.
 */
void forward_list_sort(ForwardList *l);

/**
 * @brief Destroys the linked list.
 *  Frees the memory allocated for the linked list and all its nodes.
 * @param l
 * Pointer to the linked list.
 *
 */
void forward_list_destroy(ForwardList *l) {
    Node *n = l->head;
    while (n != NULL) {
        Node *next = n->next;
        node_destroy(n);
        n = next;
    }
    free(l);
}