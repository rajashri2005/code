#include<stdio.h>
int main()
{
    int n,arr[100],i,j,temp;
    printf("enter the no of element");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    { 
    scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++)
    {
    for(j=i+1;j<n-i;j++)
    {
        if(arr[i]>arr[j])
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }

    }
    printf("sorted array");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);

    }
    return 0;
   
   
       
}
