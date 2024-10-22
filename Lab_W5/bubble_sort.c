#include <stdio.h>
#include <stdlib.h>
// copy your swap function from reverse_array.c
void swap(int *arr, int N)
{
    int temp;
    for (int i = 0; i < N/2; i++){
        temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-i-1] = temp;
    }
}

void bubble_sort(int *arr, int N)
{
    // loop to access each array element
  for (int step = 0; step < N - 1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < N - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (arr[i] > arr[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    bubble_sort(arr, 5);
    printf("Sorted Array in Ascending Order:\n");
    printArray(arr, 5);
    return 0; // set break point
}