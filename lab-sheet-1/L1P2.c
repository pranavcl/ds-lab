#include <stdio.h>
 
int main()
{
    int n, i, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
 
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    printf("Enter element to search: ");
    scanf("%d", &key);
 
    int low = 0, high = n-1, mid;
 
    do {
       mid = (low+high)/2;
       if(arr[mid] < key) low = mid+1;
       else if(arr[mid] > key) high = mid-1;
       else break;
    } while(low <= high);
 
    if(arr[mid] == key) {
        printf("Element found at index %d!\n", mid);
        return 0;
    }
 
    printf("Element not found.\n");
 
    return 0;
}
