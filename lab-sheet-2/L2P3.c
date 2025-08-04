#include<stdio.h>
#include<stdlib.h>

int** matrix_mul(int** a, int** b, int m1, int n1, int m2, int n2) {
	int i, j, k;
	int** arr = (int**)malloc(m1 * sizeof(int*));

	for(i = 0; i < m1; i++) {
		*(arr + i) = (int*)malloc(n2 * sizeof(int));
	}

	for(i = 0; i < m1; i++) {
		for(j = 0; j < n2; j++) {
			*(*(arr + i) + j) = 0;

			for(k = 0; k < n1; k++) {
				*(*(arr + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
			}
		}
	}

	return arr;
}

int main() {
	int i, j, m1, n1, m2, n2;
	printf("Enter the number of rows in matrix A: ");
	scanf("%d", &m1);
	printf("Enter the number of cols in matrix A: ");
	scanf("%d", &n1);

	int** arr = (int**)malloc(m1 * sizeof(int*));
	for(i = 0; i < m1; i++) {
		*(arr + i) = (int*)malloc(n1 * sizeof(int));
	}

	printf("Enter the matrix A elements:\n");
	for(i = 0; i < m1; i++) {
		for(j = 0; j < n1; j++) {
			scanf("%d", *(arr + i) + j);
		}
	}

	printf("Enter the number of rows in matrix B: ");
	scanf("%d", &m2);
	printf("Enter the number of cols in matrix B: ");
	scanf("%d", &n2);

	int** arr1 = (int**)malloc(m2 * sizeof(int*));
	for(i = 0; i < m2; i++) {
		*(arr1 + i) = (int*)malloc(n2 * sizeof(int));
	}

	printf("Enter the matrix B elements:\n");
	for(i = 0; i < m1; i++) {
		for(j = 0; j < n1; j++) {
			scanf("%d", *(arr1 + i) + j);
		}
	}

	printf("\nMatrix A:\n");
	for(i = 0; i < m1; i++) {
		for(j = 0; j < n1; j++) {
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}

	printf("\nMatrix B:\n");
	for(i = 0; i < m2; i++) {
		for(j = 0; j < n2; j++) {
			printf("%d\t", *(*(arr1 + i) + j));
		}
		printf("\n");
	}

	if(n1 != m2) {
		printf("Multiplication is not possible!\n");
		return 1;
	}

	int** product = matrix_mul(arr, arr1, m1, n1, m2, n2);

	printf("\nA * B =\n");
	for(i = 0; i < m1; i++) {
		for(j = 0; j < n2; j++) {
			printf("%d\t", *(*(product + i) + j));
		}
		printf("\n");
	}

	for(int i = 0; i < m1; i++) {
	        free(*(arr+i));
	        free(*(product+i));
	}
	for(int i = 0; i < m2; i++) {
	        free(*(arr1+i));
	}
	free(arr);
	free(arr1);
	free(product);
	
	return 0;
}
