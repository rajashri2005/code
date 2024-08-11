#include<stdio.h>
int main()
{
    int n,i,a[100],num ,found=0;
    printf("enter the value of element\n");
    scanf("%d",&n);

    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d\n",&a[i]);

    }
    printf("enter the element you want to search\n");
    scanf("%d",&num);
    

for(i=0;i<n;i++)
{
    if(a[i]==num)
    {
        found=1;
        printf("the num is found at %d position\n",i+1);
       
        break;

    }
    if( found==0)
    {
        printf("the number is not found\n");

    }
}
return 0;
}