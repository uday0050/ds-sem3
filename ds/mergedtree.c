#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
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

// Function to insert a value into the binary tree
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

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to merge two binary trees into a third tree
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL) {
        return root2;
    }
    if (root2 == NULL) {
        return root1;
    }

    struct TreeNode* mergedRoot = createNode(root1->data);

    mergedRoot->left = mergeTrees(root1->left, root2->left);
    mergedRoot->right = mergeTrees(root1->right, root2->right);

    return mergedRoot;
}

int main() {
    struct TreeNode* tree1 = NULL;
    struct TreeNode* tree2 = NULL;
    struct TreeNode* mergedTree = NULL;

    int value;
    char choice;

    // Create the first binary tree
    printf("Enter values for the first binary tree (enter 'x' to stop):\n");
    do {
        printf("Enter a value: ");
        if (scanf("%d", &value) == 1) {
            tree1 = insert(tree1, value);
        } else {
            scanf("%c", &choice); // Clear the input buffer
            break;
        }
    } while (1);

    // Create the second binary tree
    printf("\nEnter values for the second binary tree (enter 'x' to stop):\n");
    do {
        printf("Enter a value: ");
        if (scanf("%d", &value) == 1) {
            tree2 = insert(tree2, value);
        } else {
            scanf("%c", &choice); // Clear the input buffer
            break;
        }
    } while (1);

    // Merge the two binary trees into a third tree
    mergedTree = mergeTrees(tree1, tree2);

    // Display the in-order traversal of the merged tree
    printf("\nIn-order traversal of the merged binary tree: ");
    inOrderTraversal(mergedTree);
    printf("\n");

    // Clean up memory
    // Implementing a function to free the memory in a more complex scenario is recommended
    free(tree1);
    free(tree2);
    free(mergedTree);

    return 0;
}
