#include<stdio.h>
#include<stdlib.h>
#include "utilities.h"
#include"core.h"


int **create_2D_array(struct values val)
{
    int i;

    val.p = (int **) malloc(val.m * sizeof(int *));
    
    for(i = 0; i < val.m; i++) {
        val.p[i] = (int *) malloc(val.n * sizeof(int));
    }
    
    return val.p;
}


void randnum(struct values val)
{
    int i,j;
    
    srand(time(NULL));
    
    for(i = 0; i < val.m; i++) {
        for(j = 0; j < val.n; j++) {
            val.p[i][j] = rand() % LIMIT;
        }
    }
}

