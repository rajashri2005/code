#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* p = (Node*) malloc(sizeof(Node));
    if (!p) {
        printf("Memory error\n");
        return NULL;
    }
    p->data = data;
   p->next = NULL;
    return p;
}


void insertNode(Node** head, int data) {
    Node* q = createNode(data);
    if (*head == NULL) {
        *head = q;
        return;
    }
Node* lastNode = *head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    lastNode->next = q;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    printList(head);
    return 0;
}



