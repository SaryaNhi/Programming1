#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int sum(int a, int b)
{
    return a + b;
}

/**
 * Write reduce function where func is one of "max", "min", "sum"
 * Return func(array)
*/
int reduce(int** arr, int N, int M, const char* func)
{
    assert(N > 0 && M > 0);

    int result;
    if (strcmp(func, "max") == 0) {
        result = arr[0][0];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result = max(result, arr[i][j]);
            }
        }
    } else if (strcmp(func, "min") == 0) {
        result = arr[0][0];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result = min(result, arr[i][j]);
            }
        }
    } else if (strcmp(func, "sum") == 0) {
        result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result = sum(result, arr[i][j]);
            }
        }
    } else {
        fprintf(stderr, "Unsupported function: %s\n", func);
        exit(EXIT_FAILURE);
    }

    return result;
}

/**
 * Write reduce function by axis where func is one of "max", "min", "sum"
 * The return value should be 1-dimensional array
 * Return func(array, axis)
*/
int* reduce_with_axis(int** arr, int N, int M, const char* func, int axis)
{
    assert(N > 0 && M > 0);
    int* out;

    if (axis == 0) {
        out = malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            out[j] = arr[0][j];
            for (int i = 1; i < N; i++) {
                if (strcmp(func, "max") == 0) {
                    out[j] = max(out[j], arr[i][j]);
                } else if (strcmp(func, "min") == 0) {
                    out[j] = min(out[j], arr[i][j]);
                } else if (strcmp(func, "sum") == 0) {
                    out[j] = sum(out[j], arr[i][j]);
                }
            }
        }
    } else if (axis == 1) {
        out = malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            out[i] = arr[i][0];
            for (int j = 1; j < M; j++) {
                if (strcmp(func, "max") == 0) {
                    out[i] = max(out[i], arr[i][j]);
                } else if (strcmp(func, "min") == 0) {
                    out[i] = min(out[i], arr[i][j]);
                } else if (strcmp(func, "sum") == 0) {
                    out[i] = sum(out[i], arr[i][j]);
                }
            }
        }
    } else {
        fprintf(stderr, "Unsupported axis: %d\n", axis);
        exit(EXIT_FAILURE);
    }

    return out;
}

/**
 * Write transpose function to transpose NxM array -> MxN array
*/
int** transpose(int** two_array, int N, int M)
{
    int** transposed_array = malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++) {
        transposed_array[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            transposed_array[i][j] = two_array[j][i];
        }
    }

    return transposed_array;
}

int main()
{
    // set random seed to current time
    srand(time(NULL));

    int N = 3, M = 4;
    // allocate NxM array
    int** two_array = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
    {
        two_array[i] = malloc(M * sizeof(int));

        // set random value (0->9) for each element of array
        for (int j = 0; j < M; j++)
        {
            two_array[i][j] = rand() % 10;
            printf("array[%d][%d] = %d\n", i, j, two_array[i][j]);
        }
    }

    int reduced = reduce(two_array, N, M, "max");
    printf("Max of all elements: %d\n", reduced);

    int* reduced_axis = reduce_with_axis(two_array, N, M, "max", 0);
    printf("Max across rows: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", reduced_axis[i]);
    }
    printf("\n");

    int** transposed_array = transpose(two_array, N, M);
    printf("Transposed array:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", transposed_array[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(two_array[i]);
    }
    free(two_array);
    free(reduced_axis);
    for (int i = 0; i < M; i++) {
        free(transposed_array[i]);
    }
    free(transposed_array);

    return 0;
}
