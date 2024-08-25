#include<stdio.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Eement:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

head->data=7;
head->next=second;
second->data=11;
second->next=third;
third->data=4;
third->next=fourth;
fourth->data=9;
fourth->next=NULL;
printf("linked list before deletion");
linkedListTraversal(head);
head = deleteFirst(head);
printf("linked list after deletion");
linkedListTraversal(head);
return 0;
}