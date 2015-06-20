#include<stdio.h>
#include<stdlib.h>
#include"utilities.h"
#include"print.h"
void shifting(int **p, int m, int n, int shift);

int same_numbers_row(int **p, int m, int n, int *count, int *row, int *column)
{
    int i,j,y;
    int counter=1;
    for(i=0;i<m;i++){
        for(j=0;j<=n-3;j++){
            y=j;
            while(y<n-1 && p[i][y]==p[i][y+1]){
                y++;
                counter++;
            }
            if(counter>2){
                (*row)=i;
                (*column)=j;
                (*count)=counter;
                return 1;
            }
            counter=1;
        }
    }
    return 0;
}

int same_numbers_column(int **p, int m, int n, int *count, int *row, int *column)
{
    int i,j,y;
    int counter=1;
    for(i=0;i<n;i++){
        for(j=0;j<=m-3;j++){
            y=j;
            while(y<m-1 && p[y][i]==p[y+1][i] ){
                y++;
                counter++;
            }
            if(counter>2){
                (*row)=i;
                (*column)=j;
                (*count)=counter;
                return 1;
            }
            counter=1;
        }

    }
    return 0;
}

int initialize(int **p, int m, int n)
{
    int count,row,column,shift;
    p=create_2D_array(m, n);

    randnum(p, m, n);

    while(same_numbers_row(p, m, n, &count, &row, &column) || same_numbers_column(p, m, n, &count, &row, &column)){
        p[row][column+1]=rand() % LIMIT;
        p[column+1][row]=rand() % LIMIT;
    }
    print(p, m, n);

    printf("\nEnter the number of shifting : \n");
    scanf("%d",&shift);
    shifting(p, m, n, shift);
    return;
}

void shifting(int **p, int m, int n, int shift)
{
    int i,j,k;
    printf("shift - %d\n",shift);
    for(k=0; k<shift; k++){
        for(i=m-1; i>0; i--){
            for(j=n-1; j>=0; j--){
                p[i][j]=p[i-1][j];
            }
        }
    }

    for(i=0; i<shift; i++){
        for(j=0; j<n; j++){
            p[i][j]=rand() % LIMIT;
        }
    }

    printf("After shifting : \n");

    print(p, m, n);
}
