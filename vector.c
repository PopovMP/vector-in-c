#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define VECTOR_INITIAL_CAPACITY (8)

Vector* vector_make(void) {
    Vector* vec = malloc(sizeof(Vector));
    if (vec == NULL) {
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    vec->capacity = VECTOR_INITIAL_CAPACITY;
    vec->length = 0;
    vec->data = malloc(sizeof(long) * vec->capacity);
    if (vec->data == NULL) {
        free(vec);
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    return vec;
}

size_t vector_push(Vector* vec, long num) {
    if (vec == NULL) {
        fprintf(stderr, "Vector is NULL!\n");
        exit(EXIT_FAILURE);
    }

    if (vec->length == vec->capacity) {
        vec->capacity = 2 * vec->capacity;
        void* new_data = realloc(vec->data, sizeof(long) * vec->capacity);
        if (new_data == NULL) {
            fprintf(stderr, "Cannot re-allocate memory!\n");
            free(vec->data);
            free(vec);
            exit(EXIT_FAILURE);
        }
        vec->data = new_data;
    }

    vec->data[vec->length] = num;
    vec->length += 1;
    return vec->length;
}

long vector_pop(Vector* vec) {
    if (vec->length == 0) {
        fprintf(stderr, "Vector is empty!\n");
        exit(EXIT_FAILURE);
    }

    vec->length -= 1;

    if (vec->length < vec->capacity / 4 && vec->capacity / 2 >= VECTOR_INITIAL_CAPACITY) {
        vec->capacity = vec->capacity / 2;
        void* new_data = realloc(vec->data, sizeof(long) * vec->capacity);
        if (new_data == NULL) {
            fprintf(stderr, "Cannot re-allocate memory!\n");
            free(vec->data);
            free(vec);
            exit(EXIT_FAILURE);
        }
        vec->data = new_data;
    }

    return vec->data[vec->length];
}

long vector_get(Vector* vec, size_t i) {
    if ((long long) i < 0 || i >= vec->length) {
        fprintf(stderr, "Vector range error!\n");
        exit(EXIT_FAILURE);
    }

    return vec->data[i];
}

long vector_set(Vector* vec, size_t i, long num) {
    if ((long long) i < 0 || i >= vec->length) {
        fprintf(stderr, "Vector range error!\n");
        exit(EXIT_FAILURE);
    }

    return vec->data[i] = num;
}

size_t vector_length(Vector* vec) {
    if (vec == NULL) {
        fprintf(stderr, "Vector is NULL!\n");
        exit(EXIT_FAILURE);
    }

    return vec->length;
}

void vector_free(Vector* vec) {
    if (vec == NULL) return;
    free(vec->data);
    free(vec);
}
