# Vector in C

This is a simple implementation of a vector in C.
It is a dynamic array that can grow and shrink as needed.

It is implemented using a struct that contains a pointer to the data,
the length of the vector, and the capacity of the vector.

The vector supports the following operations:

- `vector_make`: Create a new vector with an initial capacity.
- `vector_push`: Add an element to the end of the vector.
- `vector_pop`: Remove an element from the end of the vector.
- `vector_get`: Get the element at a specific index in the vector.
- `vector_set`: Set the element at a specific index in the vector.
- `vector_length`: Get the number of elements in the vector.
- `vector_free`: Destroy a vector and free its memory.

The vector is implemented using a dynamic array that grows by a factor of 2
when the capacity is reached.

The vector shrinks by a factor of 2 when the length of the vector is less than half of the capacity.
This ensures that the vector does not waste memory when elements are removed.

The implementation is provided in the `vector.c` and `vector.h` files.

The `main.c` file contains a simple test program that demonstrates the usage of the vector.

To compile and run the test program, use the following commands:

```bash
make
./main
```

## API

```c
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
```

