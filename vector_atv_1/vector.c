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

data_type vector_remove(Vector *v, int i) {
    if (i >= 0 && i < v->size) {
        data_type val = v->data[i];
        for (int j = i; j < v->size - 1; j++) {
            v->data[j] = v->data[j + 1];
        }
        v->size--;
        return val;
    }
    printf("O indice informado eh negativo ou maior que o tamanho do vetor");
    exit(1);
}

data_type vector_pop_front(Vector *v) {
    return vector_remove(v, 0);
}

data_type vector_pop_back(Vector *v) {
    return vector_remove(v, v->size - 1);
}

Vector *vector_copy(Vector *v) {
    Vector *copy = vector_construct();
    for (int i = 0; i < v->size; i++) {
        vector_push_back(copy, v->data[i]);
    }
    return copy;
}

void vector_insert(Vector *v, int i, data_type val) {
    if (v->size >= v->allocated) {
        v->allocated += 10;
        v->data = (data_type *) realloc(v->data, v->allocated * sizeof(data_type));
        if (v == NULL) {
            printf("Memoria insuficiente para aumentar o tamanho do vetor.\n");
            exit(1);
        }
    }

    Vector *copy = vector_copy(v);

    for (int j = i; j < v->size; j++) {
        v->data[j+1] = copy->data[j];
    }
    v->data[i] = val;
    v->size++;

    vector_destroy(copy);
}

void vector_swap(Vector *v, int i, int j) {
    data_type copy = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = copy;
}

void vector_sort(Vector *v) {
    for (int i = 0; i < v->size - 1; i++) {
        for (int j = i + 1; j < v->size; j++) {
            if (v->data[i] > v->data[j]) {
                vector_swap(v, i, j);
            }
        }
    }
}

/*int vector_binary_search(Vector *v, data_type val) {
    vector_sort(v);
    int left = 0;
    int right = v->size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (v->data[middle] == val) {
            return middle;
        } else if (v->data[middle] < val) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}*/

void vector_reverse(Vector *v) {
    for (int i = 0; i < v->size - 1; i++) {
        for (int j = i + 1; j < v->size; j++) {

            vector_swap(v, i, j);
            
        }
    }
}