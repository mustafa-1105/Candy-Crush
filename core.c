#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include<stdlib.h>
#include"utilities.h"
#include"input_output.h"
#include"core.h"

int same_numbers_row(struct values val, int *count, int *row, int *column)
{
    int i,j,y;
    int counter = 1;

    for(i = 0; i < val.m; i++){
        for(j = 0;j <= val.n-3; j++){
            y = j;
    
            while(y < val.n-1 && val.p[i][y] == val.p[i][y+1]){
                y++;
                counter++;
            }
            
            if(counter > 2){

                (*row) = i;
                (*column) = j;
                (*count) = counter;
            
                return 1;
            }

            counter = 1;
        }
    }

    return 0;
}


int same_numbers_column(struct values val, int *count, int *row, int *column)
{
    int i,j,y;
    int counter = 1;

    for(i = 0; i < val.n; i++){
        for(j = 0;j <= val.m-3; j++){
            y = j;
    
            while(y < val.m-1 && val.p[y][i] == val.p[y+1][i] ){
                y++;
                counter++;
            }
            
            if(counter > 2){

                (*row) = i;
                (*column) = j;
                (*count) = counter;
            
                return 1;
            }

            counter = 1;
        }

    }

    return 0;
}

int **initialize(struct values val)
{
    int count,row,column,shift;
    
    val.p = create_2D_array(val);

    randnum(val);

    while(same_numbers_row(val, &count, &row, &column) || same_numbers_column(val, &count, &row, &column)){
        val.p[row][column+1] = rand() % LIMIT;
        val.p[column+1][row] = rand() % LIMIT;
    }

    return val.p;
}


void shifting_rows(struct values val, int x, int y, int shift)
{
    int i;
    
    for(i=0;i<shift;i++){           
        shifting_columns(val, x, y, 1);
        y++;
    }
}


void shifting_columns(struct values val, int x, int y, int shift)
{
    int i,j,k;
 
    for(k=0; k<shift; k++){
        for(i=x-1; i>0; i--){
            val.p[i][y-1]=val.p[i-1][y-1];
        }
    }

    for(i=0; i<shift; i++){
        val.p[i][y-1]=rand() % LIMIT;
    }
}


int _switch(struct values val)
{

    int temp,count;
    int row;
    int column;
    int a = val.x-1;
    int b = val.y-1;
    int m = val.m;
    int n = val.n;
    
    if(val.direction == 'u'){
        
        temp = val.p[a-1][b];
        val.p[a-1][b] = val.p[a][b];
        val. p[a][b] = temp;
    }   else if(val.direction == 'd'){
      
        temp = val.p[a+1][b];
        val.p[a+1][b] = val.p[a][b];
        val.p[a][b] = temp;  
    }   else if(val.direction == 'l'){
        
        temp = val.p[a][b-1];
        val.p[a][b-1] = val.p[a][b];
        val.p[a][b] = temp;  
    }   else if(val.direction == 'r'){
        
        temp = val.p[a][b+1];
        val.p[a][b+1] = val.p[a][b];
        val.p[a][b] = temp;  
    }

    return 0;
}


int reverse_switch(struct values val)
{
    if(val.direction == 'u'){

        val.direction = 1;
    }   else if(val.direction == 'd'){

        val.direction = 0;
    }   else if(val.direction == 'l'){

        val.direction = 2;
    }   else if(val.direction == 'r'){

        val.direction = 3;
    }

    call_switch(val, val.direction);

    return 0;
}


int call_switch(struct values val, int ch){

    if(ch == 0){

        val.cursor_x = val.cursor_x-1;
        val.x = val.cursor_x+2;
        val.y = val.cursor_y+1;
        val.direction = 'u';
    }

    if(ch == 1){

        val.x = val.cursor_x = val.cursor_x+1;
        val.y = val.cursor_y+1;
        val.direction = 'd';
    }

    if(ch == 2){

        val.y = val.cursor_y = val.cursor_y+1;
        val.x = val.cursor_x+1;
        val.direction = 'r';
    }

    if(ch == 3){

        val.y = val.cursor_y = val.cursor_y-1;
        val.x = val.cursor_x+1;
        val.y = val.cursor_y+2;
        val.direction = 'l';
    }
   
    _switch(val);

    return 1;
}


