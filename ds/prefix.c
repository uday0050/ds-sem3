#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int arr[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a prefix expression
int evaluatePrefixExpression(char expression[]) {
    struct Stack stack;
    initialize(&stack);

    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            // If the current character is a digit, push it onto the stack
            push(&stack, expression[i] - '0');
        } else {
            // If the current character is an operator, pop two operands from the stack,
            // perform the operation, and push the result back onto the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    // The final result will be at the top of the stack
    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];

    // Get the prefix expression from the user
    printf("Enter a prefix expression: ");
    scanf("%s", expression);

    // Evaluate the expression and print the result
    int result = evaluatePrefixExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
