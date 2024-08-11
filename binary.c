#include<stdio.h>
int main()
{
    int arr[100],n,x;

    printf("enter the no of elements:");
    scanf("%d",&n);

    printf("enter array elements:\n");
    for(int i=0;i<n;i++ ){
        scanf("%d",&arr[i]);
    }
    printf("enter the element u want to search in arra:");
    scanf("%d",&x);

    int lb = 0 , ub = n-1 ;
    

    while(lb<ub){
        int mid = (lb+ub)/2;
        if(arr[mid]==x){
            printf("element found at: %d",mid+1);
            break;
        }
        else if(arr[mid]>x){
            ub = mid - 1;
        }
        else if(arr[mid]<x){
            lb = mid +1 ;
        }
        else
        {
           printf("invalid element\n");
           break;
        }
    }
    return 0;

}

