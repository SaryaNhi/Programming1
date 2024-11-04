#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top; // also the head of the linked list
};

struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("\nStack Overflow");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Stack* stack, int data) {
    struct Node* new_node = createNode(data);
    if (!new_node) {
        return; // Stack overflow
    }
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("\nStack Underflow");
        return INT_MIN; // Error value
    }
    struct Node* temp = stack->top;
    int popped_data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped_data;
}

// Return 1 if the stack is empty, otherwise 0
int is_empty(const struct Stack* stack) {
    return stack->top == NULL ? 1 : 0;
}

int main() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    while (!is_empty(stack)) {
        printf("%d\n", pop(stack));
    }

    free(stack);

    return 0;
}
