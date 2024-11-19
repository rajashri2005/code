#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Fixed size for the circular queue

int MyQueue[MAX];
int R = -1; // Rear
int F = -1; // Front

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    do {
        printf("\nPress 1 for Insert\nPress 2 for Delete\nPress 3 for Display\nPress 4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert an element into the circular queue
void enqueue() {
    int item;
    if ((R + 1) % MAX == F) { // Check if the queue is full
        printf("Queue is overflow or full.\n");
        return;
    }

    printf("Enter the value of item: ");
    scanf("%d", &item);

    if (F == -1) { // First insertion
        F = 0;
        R = 0;
    } else {
        R = (R + 1) % MAX; // Increment rear circularly
    }

    MyQueue[R] = item;
    printf("Inserted: %d\n", item);
}

// Function to delete an element from the circular queue
void dequeue() {
    if (F == -1) { // Check if the queue is empty
        printf("Queue is underflow or empty.\n");
        return;
    }

    printf("Deleted: %d\n", MyQueue[F]);

    if (F == R) { // If the queue has only one element
        F = -1;
        R = -1; // Reset to empty
    } else {
        F = (F + 1) % MAX; // Increment front circularly
    }
}

// Function to display the circular queue
void display() {
    if (F == -1) { // Check if the queue is empty
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = F;
    while (1) {
        printf("%d ", MyQueue[i]);
        if (i == R) { // Stop when we reach the rear
            break;
        }
        i = (i + 1) % MAX; // Move circularly
    }
    printf("\n");
}