#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void) {
    Vector* vec = vector_make();
    if (vec == NULL) return EXIT_FAILURE;

    vector_push(vec, 13);
    printf("Vector[0]: %ld\n", vector_get(vec, 0));
    vector_set(vec, 0, 42);
    printf("Vector[0]: %ld\n", vector_get(vec, 0));
    printf("Vector length: %ld\n", (long) vector_length(vec));
    vector_pop(vec);

    for (size_t i = 1; i <= 100; i += 1)
        vector_push(vec, (long) i);

    printf("Vector length: %ld\n", (long) vector_length(vec));

    long sum = 0;
    for (size_t i = 0; i < vector_length(vec); i += 1)
        sum += vector_get(vec, i);

    printf("Sum from 1 to 100 is: %ld\n", sum);

    while (vector_length(vec))
        vector_pop(vec);

    printf("Vector length: %ld\n", (long) vector_length(vec));

    vector_free(vec);

    return EXIT_SUCCESS;
}
