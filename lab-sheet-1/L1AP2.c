#include <stdio.h>
 
int main()
{
    int m, n;
 
    printf("Enter the no. of rows in the matrices: ");
    scanf("%d", &m);
    printf("Enter the no. of cols in the matrices: ");
    scanf("%d", &n);
 
    int A[m][n], B[m][n], C[m][n];
 
    printf("Enter the elements in matrix A:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
 
    printf("Enter the elements in matrix B:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            if(A[i][j] > B[i][j]) C[i][j] = A[i][j];
            else C[i][j] = B[i][j];
        }
    }
 
    printf("Matrix C:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
