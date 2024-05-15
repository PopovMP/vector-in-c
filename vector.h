#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    size_t capacity; /* Vector capacity   */
    size_t length;   /* Data array length */
    long*  data;     /* Data array        */
} Vector;

/* Make a new empty Vector */
Vector* vector_make(void);

/* Push a new element to the end of the Vector */
size_t vector_push(Vector* vec, long num);

/* Pop the last element from the Vector */
long vector_pop(Vector* vec);

/* Get the element at index i */
long vector_get(Vector* vec, size_t i);

/* Set the element at index i to num */
long vector_set(Vector* vec, size_t i, long num);

/* Get the length of the Vector */
size_t vector_length(Vector* vec);

/* Free the Vector */
void vector_free(Vector* vec);

#endif
