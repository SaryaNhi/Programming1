#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/// @brief  function to create a node
struct Node *createNode(int data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Build the following tree
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
*/
struct Node *buildCustomTree()
{
    struct Node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);

    root->left->left = createNode(20);
    root->left->right = createNode(40);
    
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    return root;
}

// Function to free the memory of the tree
void freeMemory(struct Node *root)
{
    if (root == NULL) return;

    // Free left and right subtrees recursively
    freeMemory(root->left);
    freeMemory(root->right);

    // Free the current node
    free(root);
}

// A utility function to do inorder traversal of the tree
void inorder(struct Node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = buildCustomTree();
    
    // Perform inorder traversal
    inorder(root);  // Output will be: 20 30 40 50 60 70 80
    printf("\n");

    // Free the allocated memory
    freeMemory(root);
    
    return 0;
}
