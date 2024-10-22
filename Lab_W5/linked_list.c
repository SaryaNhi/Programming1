#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert a node with data to the end of the list
void push_back(struct Node *head, int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    struct Node *current = head;
    while (current->next != NULL) // Traverse to the end of the list
    {
        current = current->next;
    }
    current->next = new_node; // Attach the new node at the end
}

// Convert array to linked list
struct Node *toLinkedList(int *data_arr, int N)
{
    if (N == 0) return NULL; // Handle empty array case

    struct Node *head = malloc(sizeof(struct Node));
    head->data = data_arr[0];
    head->next = NULL;

    for (int i = 1; i < N; i++) // Start from the second element
    {
        push_back(head, data_arr[i]);
    }

    return head;
}

// Get data from the linked list as an array
int *getData(struct Node *head)
{
    int *out = NULL;
    int size = 0;
    struct Node *current = head;

    while (current != NULL)
    {
        size++;
        out = realloc(out, size * sizeof(int));
        out[size - 1] = current->data; // Copy data to the array
        current = current->next;
    }

    return out;
}

// Function to print the array for testing
void printArray(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    struct Node *linked_list = toLinkedList(arr, 5);

    // Extract data back from the linked list
    int *retrieved_data = getData(linked_list);
    
    // Print the retrieved data for testing
    printArray(retrieved_data, 5);

    // Free the allocated memory
    free(retrieved_data);
    struct Node *temp;
    while (linked_list != NULL) {
        temp = linked_list;
        linked_list = linked_list->next;
        free(temp);
    }

    return 0; // set break point
}
