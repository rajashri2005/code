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

struct Node * deleteByValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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
linkedListTraversal(head );
head = deleteByValue(head,11);
printf("linked list after deletion");
linkedListTraversal(head);
return 0;
}