#include <stdlib.h>
#include <string.h>

#include "vemi.h"

void vemi_vector_init(VemiVector *vec, int element_size) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->element_size = element_size;
}

void vemi_vector_push(VemiVector *vec, const void *value) {
    if (vec->size == vec->capacity) {
        size_t new_capacity = vec->capacity == 0 ? 4 : vec->capacity * 2;

        int *temp = realloc(vec->data, new_capacity * sizeof(int));

        if (temp == NULL) {
            return;
        }

        vec->data = temp;
        vec->capacity = new_capacity;
    }

    void *destination =
        (unsigned char *)vec->data + (vec->size * vec->element_size);

    memcpy(destination, value, vec->element_size);

    vec->size++;
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
