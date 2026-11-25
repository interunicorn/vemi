#ifndef VEMI_H
#define VEMI_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} VemiVector;

void vemi_vector_init(VemiVector *vec);
void vemi_vector_push(VemiVector *vec, int value);
void vemi_vector_pop(VemiVector *vec);
void vemi_vector_free(VemiVector *vec);

#endif
