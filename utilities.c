#include<stdio.h>
#include<stdlib.h>
#define LIMIT 6
int **create_2D_array(int m, int n)
{
    int **p;
    int i;
    p = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < m; i++) {
        p[i] = (int *) malloc(n * sizeof(int));
    }
    return p;
}


void randnum(int **p, int m, int n)
{
    int i,j;
    srand(time(NULL));
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            p[i][j] = rand() % LIMIT;
        }
    }
}

