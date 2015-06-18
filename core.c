#include<stdio.h>
#include<stdlib.h>
int same_numbers_row(int **p, int m, int n, int *count, int *row, int *column)
{
    int i,j,y;
    int counter=1;
    for(i=0;i<m;i++){
        for(j=0;j<n-3;j++){
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
        for(j=0;j<m-3;j++){
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

//int initialise
