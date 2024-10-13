
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for operators
char stack[MAX];
int top = -1;

// Stack structure for the result (prefix)
char result[MAX];

// Function to push an element to the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to reverse a string
void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char* infix) {
    int i, j = 0;
    int length = strlen(infix);

    // Reverse the infix expression
    reverse(infix);

    // Traverse the reversed infix expression
    for (i = 0; i < length; i++) {
        char c = infix[i];

        // If character is operand, add to result
        if (isalnum(c)) {
            result[j++] = c;
        }
        // If character is ')', push to stack
        else if (c == ')') {
            push(c);
        }
        // If character is '(', pop until ')' is found
        else if (c == '(') {
            while (top != -1 && stack[top] != ')') {
                result[j++] = pop();
            }
            pop(); // Pop ')'
        }
        // If character is an operator
        else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                result[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        result[j++] = pop();
    }

    // Terminate the result string
    result[j] = '\0';

    // Reverse the result to get the correct prefix expression
    reverse(result);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix
    infixToPrefix(infix);

    // Display the prefix expression
    printf("Prefix expression: %s\n", result);

    return 0;
}
