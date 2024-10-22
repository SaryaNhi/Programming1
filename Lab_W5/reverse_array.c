#include <stdio.h>
#include <stdlib.h>

// define your swap function here
void swap(int *arr, int N)
{
    int temp;
    for (int i = 0; i < N/2; i++){
        temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-i-1] = temp;
    }
}
// reverse array function
void reverse_array(int *arr, int N)
{
    // your code here
    swap(arr, N);
    printf("The reverse array: ");
    for (int i = 0; i<N; i++){
        printf("%d ", arr[i]);
    }
    // use your swap function
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    reverse_array(arr, 5);

    return 0; // set break point
}