#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    int id;
    char name[50];
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

// Function to enqueue a person at the rear of the queue
void enqueue(struct Queue* queue, int id, const char* name) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }

    // Set the data and next pointer of the new node
    newNode->id = id;
    strcpy(newNode->name, name);
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

    printf("Person with ID %d and name %s entered the party.\n", id, name);
}

// Function to dequeue a person from the front of the queue
void dequeueFront(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Remove the front node and update the front pointer
    struct Node* temp = queue->front;
    printf("Person with ID %d and name %s exited from the front of the party.\n", temp->id, temp->name);

    queue->front = queue->front->next;

    // If the queue becomes empty after dequeue, update the rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

// Function to dequeue a person from the rear of the queue
void dequeueRear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Remove the rear node and update the rear pointer
    struct Node* temp = queue->rear;
    printf("Person with ID %d and name %s exited from the rear of the party.\n", temp->id, temp->name);

    struct Node* current = queue->front;
    // If there is only one person in the party, update both front and rear pointers to NULL
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        // Otherwise, traverse the list to find the second-to-last node
        while (current->next != queue->rear) {
            current = current->next;
        }
        // Update the rear pointer and free the last node
        queue->rear = current;
        current->next = NULL;
    }

    free(temp);
}

// Function to display the details of people in the party
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Party is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Details of people in the party:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

int main() {
    struct Queue partyQueue;
    initializeQueue(&partyQueue);

    int choice, id;
    char name[50];

    do {
        printf("\nParty Menu:\n");
        printf("1. Enter the party\n");
        printf("2. Exit from the front\n");
        printf("3. Exit from the rear\n");
        printf("4. Display details of people in the party\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                enqueue(&partyQueue, id, name);
                break;
            case 2:
                dequeueFront(&partyQueue);
                break;
            case 3:
                dequeueRear(&partyQueue);
                break;
            case 4:
                display(&partyQueue);
                break;
            case 5:
                printf("Exiting the party.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}