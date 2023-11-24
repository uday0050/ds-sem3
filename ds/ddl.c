#include <stdio.h>
#include <stdlib.h>

typedef struct node *listptr;
struct node{
    int data;
    listptr next,prev;
};

listptr addToEmpty(listptr head, int data){
    listptr temp = (listptr)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

listptr addAtB(listptr head, int data){
    listptr temp = (listptr)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp->next = head;
    head->prev = temp;
    // temp = head->prev;
    // head->next = NULL;
    head=temp;
    return head;
} 

struct node* addAtEnd(struct node* head, int data){
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while(tp->next != NULL){
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

listptr addAtIndex(listptr head,int data ,int index){
    listptr temp = malloc(sizeof(struct node));
    listptr tp;
    int i=1;
    temp->data = data;
    tp=head;
    while(i != index){
        tp=tp->next;
        i++;
    }
    temp->next=tp->next;
    tp->next->prev=temp;
    tp->next=temp;
    temp->prev=tp;
    // tnext=tp->next;
    // tnext->prev=temp;
    // tnext->next=

    // temp=tp->next;
    // tp->next=temp->next;
    // tp->next=temp;
    // temp->prev=tp;
    return head;
}
listptr delLast(listptr head){
    listptr ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return head;
}

listptr delAfter(listptr head,int value){
    listptr ptr = head;
    listptr temp;
    while(ptr -> data != value){
        ptr = ptr -> next;
    }
    if(ptr->next == NULL)
    printf("Cannot delete");
    else{
        temp = ptr->next;
        ptr->next=temp->next;
        temp->next->prev=ptr;
        free(temp);
    }
   
    return head;
}





int main(){
    listptr head=NULL;
    listptr ptr;
    head = (listptr)malloc(sizeof(struct node));
    head = addToEmpty(head,20);
    head = addAtB(head,10);
    head = addAtB(head,5);
    head = addAtIndex(head,15,2);
    head = delLast(head);
    head = delAfter(head,10);
    ptr = head;
    while(ptr != NULL){
        printf("%d \t",ptr -> data);
        ptr = ptr -> next;
    }


    

    return 0;
}