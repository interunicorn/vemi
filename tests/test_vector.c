#include <assert.h>
#include <stdio.h>
#include <vemi.h>

int main(void) {
    VemiVector vec;

    vemi_vector_init(&vec);

    vemi_vector_push(&vec, 42);

    assert(vec.size == 1);
    assert(vec.data[0] == 42);

    vemi_vector_free(&vec);

    printf("All tests passed!\n");

    return 0;
}
