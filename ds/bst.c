#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a value into the binary search tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an in-order traversal of the binary search tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    int value;
    char choice;

    // Create the binary search tree
    printf("Enter values for the binary search tree (enter '-1' to stop):\n");
    do {
        printf("Enter a value: ");
        scanf("%d",&value);
        if(value == -1)
        break;
        else 
        root = insert(root,value);   
    } while (1);

    // Display the in-order traversal of the binary search tree
    printf("\nIn-order traversal of the binary search tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Clean up memory
    // Implementing a function to free the memory in a more complex scenario is recommended
    free(root);

    return 0;
}
