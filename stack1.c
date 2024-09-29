 
#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;


void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed onto the stack.\n", value);
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top--]);
}


void printStack() {
    if (top == -1) {
        printf("Stack is empty!\n");
 return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}




 