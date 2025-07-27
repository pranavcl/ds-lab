#include<stdio.h>
#include<stdlib.h>

int find_small(int* arr, int n) {
	int i;
	int smallest = *arr;

	for(i = 1; i < n; i++) {
		if(*(arr + i) < smallest) {
			smallest = *(arr + i);
		}		
	}

	return smallest;
}

int main() {
	int n, i;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	printf("Enter the array elements:\n");
	for(i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	printf("Smallest element: %d\n", find_small(arr, n));
	free(arr);

	return 0;
}

