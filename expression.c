#include <stdio.h>
#include <ctype.h>  // For isdigit() function
#include <stdlib.h> // For atoi() function

#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to push elements onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop elements from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* exp) {
    int i;
    
    // Loop through each character in the expression
    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            // If the character is an operator, pop two elements from the stack
            int val1 = pop();
            int val2 = pop();
            
            // Perform the operation and push the result back onto the stack
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    // The final result will be on the top of the stack
    return pop();
}

int main() {
    char exp[MAX];
    
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    
    printf("The result of the expression is: %d\n", evaluatePostfix(exp));
    
    return 0;
}