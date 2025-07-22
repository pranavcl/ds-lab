#include <stdio.h>
 
int main()
{
    int n, i, j, rsum, csum, ldsum=0, rdsum=0, sum = 0;
 
    printf("Enter the no. of rows/cols in the square matrix: ");
    scanf("%d", &n);
 
    int m[n][n];
 
    printf("Enter the matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
            sum += m[i][j];
        }
        if(i == 0) rsum = sum;
        else if(sum != rsum) {
            printf("Not a magic square!\n");
            return 0;
        }
        sum = 0;
    }
 
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum += m[j][i];
            if(i == j) ldsum += m[j][i];
            if(i + j == n-1) rdsum += m[j][i];
        }
        if(i == 0) csum = sum;
        else if(sum != csum) {
            printf("Not a magic square!\n");
            return 0;
        }
        sum = 0;
    }

    printf("%d %d %d %d\n", csum, rsum, ldsum, rdsum);
 
    if(csum != rsum || rsum != ldsum || ldsum != rdsum) {
        printf("Not a magic square!\n");
        return 0;
    }
 
    printf("It is a magic square!\n");
 
    return 0;
}
