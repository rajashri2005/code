#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Fixed macro definition
 
int MyQueue[MAX];
int R = -1; // Rear
int F = -1; // Front

void enqueue();
void dequeue();
void display();

void main() {
    int choice;
    do {
        printf("\nPress 1 for Insert\nPress 2 for Delete\nPress 3 for Print\nPress 4 for Exit\n");
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
}

void enqueue() {
    int item;
    if (R == MAX - 1) {
        printf("Queue is overflow or full.\n");
        return;
    }
    printf("Enter the value of item: ");
    scanf("%d", &item);

    if (F == -1 && R == -1) { // First insertion
        F = 0;
        R = 0;
    } else {
        R++;
    }
    MyQueue[R] = item;
    printf("Inserted: %d\n", item);
}

void dequeue() {
    if (F == -1 || F > R) { // Queue is empty
        printf("Queue is underflow or empty.\n");
        return;
    }
    printf("Deleted: %d\n", MyQueue[F]);
    if (F == R) { // Last element removed
        F = -1;
        R = -1;
    } else {
        F++;
    }
}

void display() {
    if (F == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = F; i <= R; i++) {
            printf("%d ", MyQueue[i]);
        }
        printf("\n");
    }
}