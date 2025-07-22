#include <stdio.h>
 
int main()
{
    int n, i, j, choice, key, temp, swaps=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
 
    // Take input of array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    printf("Which algorithm do you want to sort with?\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    scanf("%d", &choice);
 
    switch(choice) {
    case 1:
        // ===== BUBBLE SORT =====
 
        printf("Sorting elements using bubble sort (ascending):\n");
        for(i = 0; i < n-1; i++) {
            for(j = 0; j < n-i; j++) {
                if(arr[j] > arr[j+1]) {
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
		    swaps++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
	printf("Swaps made: %d\n", swaps);
	swaps = 0;
        break;
    case 2:
        // ===== SELECTION SORT =====
 
        printf("Sorting elements using selection sort (ascending):\n");
        for(i = 0; i < n-1; i++) {
            int min_idx = i;
            for(j = i+1; j < n; j++) {
                if(arr[j] < arr[i]) {
                    min_idx = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
	    swaps++;
        }
        for(int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
	printf("Swaps made: %d\n", swaps);
	swaps = 0;
        break;
    case 3:
        // ===== INSERTION SORT =====
 
        printf("Sorting elements using insertion sort (ascending):\n");
        for(int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            while(j >= 0 && key < arr[j]) {
                arr[j+1] = arr[j];
                j -= 1;
            }
            arr[j+1] = key;
	    swaps++;
        }
        for(int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
	printf("Swaps made: %d\n", swaps);
	swaps = 0;
        break;
    default:
        printf("Invalid choice!\n");
    }
 
    return 0;
}
