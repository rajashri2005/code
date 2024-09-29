#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Stack {
    Node* top;
} Stack;


Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}


int isEmpty(Stack* stack) {
    return stack->top == NULL;
}


void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}


int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}


void printStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printStack(stack);  
    printf("Popped element: %d\n", pop(stack)); 
    printStack(stack);  
    return 0;
}


