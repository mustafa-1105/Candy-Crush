#include<stdio.h>
#include<stdlib.h>
#include"utilities.h"
#include"input_output.h"
#include"core.h"
int score;

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

int **initialize(int m, int n)
{
    int **p;
    int count,row,column,shift;
    p=create_2D_array(m, n);

    randnum(p, m, n);

    while(same_numbers_row(p, m, n, &count, &row, &column) || same_numbers_column(p, m, n, &count, &row, &column)){
        p[row][column+1]=rand() % LIMIT;
        p[column+1][row]=rand() % LIMIT;
    }

    return p;
}


void shifting_rows(int **p, int m, int n, int x, int y, int shift)
{
   int i;
   for(i=0;i<shift;i++){        
         shifting_columns(p, m, n, x, y, 1);
          y++;
   }
}


void shifting_columns(int **p, int m, int n, int x, int y, int shift)
{
    int i,j,k;
    for(k=0; k<shift; k++){
        for(i=x-1; i>0; i--){
                p[i][y-1]=p[i-1][y-1];
        }
    }

    for(i=0; i<shift; i++){
            p[i][y-1]=rand() % LIMIT;
    }
}

int _switch(struct values val, int x, int y, char direction)
{

    int temp,count;
    int row;
    int column;
    int a=x-1;
    int b=y-1;
    int **p = val.p;
    int m = val.m;
    int n = val.n;

    if(direction=='u'){
        temp=p[a-1][b];
        p[a-1][b]=p[a][b];
        p[a][b]=temp;
    }   else if(direction=='d'){
        temp=p[a+1][b];
        p[a+1][b]=p[a][b];
        p[a][b]=temp;  
    }   else if(direction=='l'){
        temp=p[a][b-1];
        p[a][b-1]=p[a][b];
        p[a][b]=temp;  
    }   else if(direction=='r'){
        temp=p[a][b+1];
        p[a][b+1]=p[a][b];
        p[a][b]=temp;  
    }
    
    while(same_numbers_row(p, m, n, &count, &row, &column) || same_numbers_column(p, m, n, &count, &row, &column)){
     
       /* if(same_numbers_column(p, m, n, &count, &row, &column) && same_numbers_row(p, m, n, &count, &row, &column)){
            shifting_columns(p, m, n, column+count, row+1, count);
            shifting_rows(p, m, n, row+1, column+1, count);

        }    else*/
        if(same_numbers_column(p, m, n, &count, &row, &column)){
                shifting_columns(p, m, n, column+count, row+1, count);
                
                if(count == 3){
                    score = score+100;
                }   else if(count == 4){
                    score = score+300;
                }
                 if(count == 5){
                    score = score+500;
                }
 
        }   else if(same_numbers_row(p, m, n, &count, &row, &column)){
                shifting_rows(p, m, n, row+1, column+1, count);
 
                if(count == 3){
                    score = score+100;
                }   else if(count == 4){
                    score = score+300;
                }
                 if(count == 5){
                    score = score+500;
                }
        }
    return 1;
    }
    
    if(direction=='u'){
        direction=='d';
        reverse_switch(p, m, n, x, y, direction);
    }   else if(direction=='d'){
        direction=='u';
        reverse_switch(p, m, n, x, y, direction);
    }   else if(direction=='l'){
        direction=='r';
        reverse_switch(p, m, n, x, y, direction);
    }   else if(direction=='r'){
        direction=='l';
        reverse_switch(p, m, n, x, y, direction);
    }

    print(val);
    return 0;
}


int reverse_switch(int **p, int m, int n, int x, int y, char direction)
{
    int temp;
    int a=x-1;
    int b=y-1;
    if(direction=='u'){
        temp=p[a-1][b];
        p[a-1][b]=p[a][b];
        p[a][b]=temp;
    }   else if(direction=='d'){
        temp=p[a+1][b];
        p[a+1][b]=p[a][b];
        p[a][b]=temp;  
    }   else if(direction=='l'){
        temp=p[a][b-1];
        p[a][b-1]=p[a][b];
        p[a][b]=temp;  
    }   else if(direction=='r'){
        temp=p[a][b+1];
        p[a][b+1]=p[a][b];
        p[a][b]=temp;  
    }
    return 0;
}

