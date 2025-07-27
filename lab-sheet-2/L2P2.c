#include<stdio.h>
#include<stdlib.h>

void selection_sort(int* arr, int n, int i, int j, int min_idx) {
	if(i >= n-1) return;
	else if(j >= n) {
		if(min_idx != i) {
			*(arr + min_idx) += *(arr + i);
			*(arr + i) = *(arr + min_idx) - *(arr + i);
			*(arr + min_idx) -= *(arr + i);
		}

		selection_sort(arr, n, i+1, i+1, i+1);
	}
	else if(*(arr + j) < *(arr + min_idx)) {
		selection_sort(arr, n, i, j+1, j);
	}
	else {
		selection_sort(arr, n, i, j+1, min_idx);
	}
}

int main() {
	int n, i;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	printf("Enter the elements: \n");

	for(i = 0; i < n; i++) {
		scanf("%d", arr + i);	
	}

	selection_sort(arr, n, 0, 1, 0);

	printf("Sorted elements:\n");
	for(i = 0; i < n; i++) {
		printf("%d,", *(arr + i));
	}

	free(arr);

	return 0;
}
