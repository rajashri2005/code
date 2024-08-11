#include<stdio.h>
int main()
{
    int n,i,arr[100],x,index;
    printf("enter the no of elements\n");
    scanf("%d",&n);
    printf("enter array elements want\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("enter the new element");
    scanf("%d",&x);
    printf(" enter the no of index");
    scanf("%d",&index);

    arr[index]=x;
    printf("updated array\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}