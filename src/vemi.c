#include "vemi.h"

#include <stdlib.h>

void vemi_vector_init(VemiVector *vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vemi_vector_push(VemiVector *vec, int value) {
    if (vec->size == vec->capacity) {
        size_t new_capacity = vec->capacity == 0 ? 4 : vec->capacity * 2;

        int *temp = realloc(vec->data, new_capacity * sizeof(int));

        if (temp == NULL) {
            return;
        }

        vec->data = temp;
        vec->capacity = new_capacity;
    }

    vec->data[vec->size++] = value;
}

void vemi_vector_pop(VemiVector *vec) {
    if (vec->size == 0) {
        return;
    }

    vec->size--;
}

void vemi_vector_free(VemiVector *vec) {
    free(vec->data);

    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}
