#include <stdio.h>
 
int main()
{
    int m, n, i, j, k;
 
    printf("Enter the no. of rows in the matrices: ");
    scanf("%d", &m);
    printf("Enter the no. of cols in the matrices: ");
    scanf("%d", &n);
 
    int A[m][n], B[m][n], C[m][n], D[m][n];
 
    printf("Enter the elements in matrix A:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
 
    printf("Enter the elements in matrix B:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            C[i][j] = A[i][j] + B[i][j];
        }
    }
 
    printf("A + B:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
 
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            D[i][j] = 0;
 
            for(k = 0; k < m; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }
 
    printf("A * B:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}
