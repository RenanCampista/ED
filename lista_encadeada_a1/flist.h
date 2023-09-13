#ifndef _FLIST_H_
#define _FLIST_H_

typedef int data_type;
typedef struct Node Node;

typedef struct Node{
    data_type value;
    Node *next;
} Node;

Node *node_create(data_type value, Node *next);

void node_destroy(Node *node);

#endif