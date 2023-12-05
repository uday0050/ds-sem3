#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
struct CircularQueue {
    int front, rear;
    int arr[MAX_SIZE];
};

// Function to initialize a circular queue
void initializeQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct CircularQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element from the circular queue
void dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue->arr[queue->front]);

    if (queue->front == queue->rear) {
        // Last element is being dequeued, reset the queue
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Elements in the queue: ");
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    int choice, value;

    do {
        printf("\nCircular Queue Menu:\n");
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
