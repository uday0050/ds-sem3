#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char arr[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Function to convert prefix to postfix expression
void prefixToPostfix(char prefix[], char postfix[]) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int i, j = 0;
    int len = strlen(prefix);

    // Process the prefix expression from right to left
    for (i = len - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            // If the current character is an operand, append it to the postfix expression
            postfix[j++] = prefix[i];
        } else {
            // If the current character is an operator
            char operand1 = pop(&operatorStack);
            char operand2 = pop(&operatorStack);

            // Construct the postfix expression by combining operands and the operator
            postfix[j++] = operand1;
            postfix[j++] = operand2;
            postfix[j++] = prefix[i];
        }
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char prefix[MAX_SIZE];
    char postfix[MAX_SIZE];

    // Get the prefix expression from the user
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert prefix to postfix and print the result
    prefixToPostfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
