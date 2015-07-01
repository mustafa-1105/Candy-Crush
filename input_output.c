#include<curses.h>
#include "utilities.h"
#include "input_output.h"
#include "core.h"

char faces[][6] = {"0", "+", "#", "@", "*", "x"};

void print(struct values val)
{

    int **p = val.p;
    int i,j,k;

    int x1=53;

    mvprintw(12, 51, "SCORE - %d",val.score);
    
    for(i=0; i< val.n; i++){
    
        x1=x1+2;
        
        mvprintw(13, x1, "%d ",i+1);
        
        mvprintw(14, x1, "--");
    }

    for(i = 0; i < val.m; i++) {
        
        int x=53;
        
        mvprintw(i+15, 50, "%2d | ",i+1);
        
        for(j = 0; j < val.n; j++) {
            x=x+2;
            int color_id = p[i][j] + 1;

            if (i == val.cursor_x && j == val.cursor_y) { 
                color_id *= 10;
            }

            attron(A_BOLD);

            attron(COLOR_PAIR(color_id));
            mvprintw(i+15, x, faces[p[i][j]]);
            attroff(COLOR_PAIR(color_id));
            attroff(A_BOLD);
        }
    }

}

int input(struct values val, int x, int y, char direction)
{
    int m = val.m;
    int n = val.n;
    if(x>0 && x<=m && y>0 && y<=n && (direction=='u' || direction=='d' || direction=='r' || direction=='l')){

        if(x==m && direction=='d'){
            return 0;
        }   else if(y==n && direction=='r'){
            return 0;
        }   else if(x==1 && direction=='u'){
            return 0;
        }   else if(y==1 && direction=='l'){
            return 0;
        }

        _switch(val, x, y, direction);
        return 0;
    } 
    return 1;
}

int accept_input()
{
    char ch;

    if ((ch = getch())== '\033') { // if the first value is esc
       
        getch(); // skip the [
    
        switch(getch()) { // the real value
        
            case 'A':
                return 0;    
                // code for arrow up
            case 'B':
                return 1;    
                // code for arrow down
            case 'C':
                return 2;    
                // code for arrow right
            case 'D':
                return 3;    
                // code for arrow left
        }
    }
    
    if(ch == '\n'){
        return 4;
        // code for arrow enter
    }   
    
    if(ch == 'q'){
        return 5;
                // code for arrow exit
    }
}

