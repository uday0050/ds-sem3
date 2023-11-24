#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Function to enqueue an element into the queue (insert at the rear)
struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = createNode(data);

    if (rear == NULL) {
        // If the queue is empty, set the new node as both front and rear
        return newNode;
    }

    rear->next = newNode;
    return newNode;
}

// Function to dequeue an element from the queue (delete from the front)
struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    struct Node* temp = front;
    front = front->next;

    printf("%d dequeued from the queue.\n", temp->data);

    free(temp);

    return front;
}

// Function to display the elements of the queue
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    struct Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    int choice;
    int value;

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
                printf("Enter data to enqueue: ");
                scanf("%d", &value);
                rear = enqueue(rear, value);
                if (front == NULL) {
                    front = rear; // If the queue was initially empty, set front to rear
                }
                displayQueue(front);
                break;

            case 2:
                front = dequeue(front);
                break;

            case 3:
                displayQueue(front);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Clean up memory
    struct Node* current = front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
