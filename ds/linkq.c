#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }

    // Set the data and next pointer of the new node
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Remove the front node and update the front pointer
    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;

    queue->front = queue->front->next;

    // If the queue becomes empty after dequeue, update the rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    printf("%d dequeued from the queue.\n", dequeuedValue);
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Elements in the queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, value;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
