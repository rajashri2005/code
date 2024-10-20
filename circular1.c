#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int data;
    struct node*next;
};
struct node*s;
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();

void traverse();


void main(){
    struct node*p,*q;
    char ch;
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the first node:");
    scanf("%d",&p->data);
    s=p;
    do{
        q=(struct node*)malloc(sizeof(struct node));
        printf("enter the data for next node:");
        scanf("%d",&q->data);
        p->next=q;
        p=q;
        printf("enter y for more nodes\n");
        ch=getch();
        
    }while(ch=='y'||ch=='Y');
    p->next=s;
    
    int choice;
    do{
        printf("press 1 for insert at beg\n");
         printf("press 2 for insert at end\n");
          printf("press 3 for delete at beg\n");
           printf("press 4 for delete at end\n");
            printf("press 5 for traverse\n");
             printf("press 0 for exit\n");
              printf("enter your choice:");
              scanf("%d",&choice);

              switch(choice){
                case 1: insert_beg(); break;
                 case 2: insert_end(); break;
                  case 3: delete_beg(); break;
                   case 4: delete_end(); break;
                    case 5: traverse(); break;
                    case 0: printf("Existing\n");
                    default: printf("invalid choice");
                
              }

    }while(choice!=0);
   
    
    return 0;
}
void insert_beg(){
    struct node*r;
    struct node*p=s;
    r=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for node to insert at beg:");
    scanf("%d",&r->data);
    while(p->next!=s){
        p=p->next;
    }
    r->next=s;
    p->next=r;
    s=r;

}
void insert_end(){
    struct node*r;
    struct node*p=s;
    r=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for the node to insert at end:");
    scanf("%d",&r->data);
    while(p->next!=s){
        p=p->next;
    }
    p->next=r;
    r->next=s;
    
}
void delete_beg(){
    struct node*p=s;
    struct node*q=s;
    while(p->next!=s){
        p=p->next;
    }
    s=s->next;
    p->next=s;
    free(q);

}
void delete_end(){
    struct node*p=s;
    struct node*q;
    while(p->next!=s){
        q=p;
        p=p->next;
    }
    q->next=s;
    free(p);
}
void traverse(){
    struct node*p=s;
    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=s);
    return 0;

}