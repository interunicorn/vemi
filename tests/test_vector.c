#include <assert.h>
#include <stdio.h>
#include <vemi.h>

int main(void) {
    VemiVector vec;

    vemi_vector_init(&vec, sizeof(int));

    int number = 69;
    vemi_vector_push(&vec, &number);

    assert(vec.size == 1);
    assert(((int *)vec.data)[0] == number);

    vemi_vector_free(&vec);

    printf("All tests passed!\n");

    return 0;
}
