#include<stdio.h>

void print(int **p, int m,int n)
{
    int i,j;
    printf("     ");
    for(i=0; i<n; i++){
        printf("%2d ",i+1);
    }

    printf("\n      ");
    for(i=0; i<n; i++){
        printf("---");
    }
    printf("\n");
    for(i = 0; i < m; i++) {
        printf("%2d | ",i+1);
        for(j = 0; j < n; j++) {
            printf("%2d ", p[i][j]);
        }
        printf("\n");
    }
}

