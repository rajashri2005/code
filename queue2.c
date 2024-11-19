#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global front (F) and rear (R) pointers
struct node *F = NULL, *R = NULL;

// Function to insert an element into the queue
void insert() {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Queue overflow\n");
        return;
    }
    
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    
    if (F == NULL) { // If queue is empty
        F = p;
        R = p;
    } else {
        R->next = p;
        R = p;
    }
}

// Function to delete an element from the queue
void delete() {
    if (F == NULL) {
        printf("Queue underflow\n");
        return;
    }
    
    struct node *p = F;
    F = F->next;
    free(p);
    
    if (F == NULL) { // If queue becomes empty
        R = NULL;
    }
}

// Function to display the queue
void display() {
    if (F == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    struct node *temp = F;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                insert();
                break;
            case 2: 
                delete();
                break;
            case 3: 
                display();
                break;
            case 4: 
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}