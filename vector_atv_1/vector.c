#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector *vector_construct() {
    Vector *v = (Vector *) calloc(1, sizeof(Vector));
    if (v == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    v->size = 0;
    v->allocated = 10;

    v->data = (data_type *) calloc(v->allocated, sizeof(data_type));
    if (v->data == NULL) {
        printf("Memoria insuficiente para alocar data.\n");
        exit(1);
    }
    return v;
}


void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val) {
    if (v->size >= v->allocated) {
        v->allocated += 10;
        v->data = (data_type *) realloc(v->data, v->allocated * sizeof(data_type));
        if (v->data == NULL) {
            printf("Memoria insuficiente para aumentar o tamanho do vetor.\n");
            exit(1);
        }
    }
    v->data[v->size] = val;
    v->size++;
}

int vector_size(Vector *v) {
    return v->size;
}

data_type vector_get(Vector *v, int i) {
    if (i >= 0 && i < vector_size(v))
        return v->data[i];
    printf("O indice informado eh negativo ou maior que o tamanho do vetor");
    exit(1);
}

void vector_set(Vector *v, int i, data_type val) {
    if (i >= 0 && i < v->size)
        v->data[i] = val;
}

int vector_find(Vector *v, data_type val) {
    for (int i = 0; i < v->size; i++) {
        if (v->data[i] == val)
            return i;
    }
    return -1;
}