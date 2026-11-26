#ifndef VEMI_H
#define VEMI_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} VemiVector;

void vemi_vector_init(VemiVector *vec, int element_size);
void vemi_vector_push(VemiVector *vec, const void *value);
void vemi_vector_pop(VemiVector *vec);
void vemi_vector_free(VemiVector *vec);

#endif
