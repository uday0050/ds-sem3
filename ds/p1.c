#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the first node from the linked list
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return NULL;
    }

    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;

    return head;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// int main() {
//     struct Node* head = NULL;

//     int value;
//     char choice;

//     // Insert elements at the end of the linked list
//     do {
//         printf("Enter a value to insert at the end (enter 'x' to stop): ");
//         if (scanf("%d", &value) == 1) {
//             head = insertAtEnd(head, value);
//             displayList(head);
//         } else {
//             scanf(" %c", &choice); // Clear the input buffer
//             if (choice == 'x') {
//                 break;
//             }
//         }
//     } while (1);

//     // Delete elements from the front of the linked list
//     do {
//         printf("\nDelete from the front? (y/n): ");
//         scanf(" %c", &choice);
//         if (choice == 'y') {
//             head = deleteFirst(head);
//             displayList(head);
//         } else if (choice == 'n') {
//             break;
//         }
//     } while (1);

//     // Clean up memory
//     struct Node* current = head;
//     while (current != NULL) {
//         struct Node* temp = current;
//         current = current->next;
//         free(temp);
//     }

//     return 0;
// }
int main() {
    struct Node* head = NULL;

    int choice;
    int value;
    do {
        printf("\nParty Menu:\n");
        printf("1. Enter \n");
        printf("2. Exit \n");  
        printf("3. Display \n");
        printf("-1. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                printf("Enter data: ");
                scanf("%d",&value);
                head = insertAtEnd(head,value);
                break;

            case 2:
                head = deleteFirst(head);
                break;
            case 3:
                displayList(head);
                break;
            case -1:
                printf("Exiting the party.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != -1);

    return 0;
}
    
    
   

