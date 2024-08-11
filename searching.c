#include<stdio.h>

int main() {
    int n, i, a[100], num, found = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &num);
    
    for(i = 0; i < n; i++) {
        if(a[i] == num) {
            found = 1;
            printf("The number is found at position %d\n", i + 1);
            break;  // Exit the loop after finding the element
        }
    }
    
    if(found == 0) {
        printf("The number is not found\n");
    }

  return 0;
}