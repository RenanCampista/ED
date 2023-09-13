#ifndef _FLIST_H_
#define _FLIST_H_

typedef int data_type;
typedef struct Node Node;

typedef struct Node{
    data_type value;
    Node *next;
} Node;

typedef struct Flist{
    Node *head;
    int size;
}Flist;

Node *node_create(data_type value, Node *next);
void node_destroy(Node *node);

Flist *flist_create();
void flist_push_front(Flist *flist, data_type value);
void flist_destroy(Flist *flist);

#endif