#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MultiArray
{
    int* data;
    int* shape;
};

/**
 * Indexing multi array using an index array
 *
 * array [2][1] = get_data(array, [2, 1])
*/
int get_data(struct MultiArray* array, int* indexes, int n_dims)
{
    int offset = 0;
    int stride = 1;

    // Calculate offset in flattened array
    for (int i = n_dims - 1; i >= 0; i--)
    {
        offset += indexes[i] * stride;
        stride *= array->shape[i];
    }

    // Access and return the value at the calculated offset
    return array->data[offset];
}

int main()
{
    // set random seed to current time
    srand(time(NULL));

    struct MultiArray* array = malloc(sizeof(struct MultiArray));

    // create 3x2x2 array
    array->data = malloc(3 * 2 * 2 * sizeof(int));

    // assign random data (0 -> 9)
    for (int i = 0; i < 3 * 2 * 2; i++)
    {
        array->data[i] = rand() % 10;
        printf("array->data[%d] = %d\n", i, array->data[i]);
    }

    // assign shape
    array->shape = malloc(3 * sizeof(int));
    array->shape[0] = 3;
    array->shape[1] = 2;
    array->shape[2] = 2;

    int indexes[] = { 1, 0, 1 };
    int out = get_data(array, indexes, 3);
    printf("Element at indexes [1][0][1] is: %d\n", out);

    // Free allocated memory
    free(array->data);
    free(array->shape);
    free(array);

    return 0;
}
