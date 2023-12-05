#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary tree node
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to evaluate an expression tree recursively
int evaluateExpressionTree(struct TreeNode* root) {
    // If the current node is a leaf, return its value
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';  // Convert char to int
    }

    // Recursively evaluate the left and right subtrees
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Perform the arithmetic operation based on the operator at the current node
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            printf("Invalid operator: %c\n", root->data);
            exit(EXIT_FAILURE);
    }
}

int main() {
    // Example expression tree: 2 * (3 + 4)
    struct TreeNode* root = createNode('*');
    root->left = createNode('2');
    root->right = createNode('+');
    root->right->left = createNode('3');
    root->right->right = createNode('4');

    // Evaluate the expression tree and print the result
    int result = evaluateExpressionTree(root);
    printf("Result: %d\n", result);

    // Free the memory used by the expression tree (optional)
    // Note: In a real-world scenario, you may want to implement a more thorough memory cleanup.
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
