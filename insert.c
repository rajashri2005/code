#include<stdio.h>
int main()
{
    int n,i,arr[100],position,value,choice;
    printf("enter the element");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("choose the insertion operation\n");
    
    printf("1.insert at the beginning\n");
    printf("2. insert at the end\n");
    printf("3.insert at any position\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("enter the value to insert at first position\n");
        scanf("%d",&value);
        for(i=n;i>0;i--)
        {
            arr[i]=arr[i-1];

        }
        arr[0]=value;
        n++;
        break;
        case 2:
        printf("enter the value insert at the end\n");
        scanf("%d\n",&value);
        arr[n]=value;
        n++;
        break;
 case 3:
    printf("enter the position where you want to insert the new element\n",n+1);
    scanf("%d",&position);
    printf("enetr the value to insert:\n");
    scanf("%d",&value);
    for(i=n;i>=position;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position-1]=value;
    n++;
    break;
    default:
    printf("invalid choice:\n");
    return 1;

    
    }
    printf("resultant array is :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);

    }
    return 0;
    
        


}