#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include"input_output.h"
#include"utilities.h"
#include"core.h"

#define ROWS 10
#define COLS 7
#define MILLI_SECONDS 1000

int main(int argc, char *argv[]) 
{    
    struct values val;
    int i,x,y;
    val.m = ROWS;
    val.n = COLS;
    x=val.cursor_x = 0;
    y=val.cursor_y = 0;
    char direction;

    if(!initscr()) {
        printf("Error initializing screen.\n");
        exit(1);
    }

    if(!has_colors()) {
        printf("This terminal does not support colours.\n");
        exit(1);
    }

    curs_set(FALSE);

    start_color();

    use_default_colors();

    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN, -1);

    init_pair(10, COLOR_RED, COLOR_WHITE);
    init_pair(20, COLOR_GREEN, COLOR_WHITE);
    init_pair(30, COLOR_YELLOW, COLOR_WHITE);
    init_pair(40, COLOR_BLUE, COLOR_WHITE);
    init_pair(50, COLOR_MAGENTA,COLOR_WHITE);
    init_pair(60, COLOR_CYAN, COLOR_WHITE);

    val.p = initialize(val.m, val.n); 

    mvprintw(0, 0, "Use Arrow keys for moving the cursor, Press Enter to select, press q to EXIT");
    
    attron(COLOR_PAIR(1));     
    
    mvprintw(12, 51, "SCORE - 0");
    
    attroff(COLOR_PAIR(1));     
    
    print(val);
    
    int ch;
    
    while(TRUE){
      
        ch=accept_input(); 
        
        if(ch == 5){
            break;
        }
    
        if(ch == 4){
        ch=accept_input(); 
        call_switch(val, ch);//;, ch, x, y, direction);
        _switch(val);//, x, y, direction);
        }
        
        if(ch == 0){
            x=val.cursor_x=val.cursor_x-1;
        }

        if(ch == 1){
            x=val.cursor_x=val.cursor_x+1;
        }

        if(ch == 2){
            y=val.cursor_y=val.cursor_y+1;
        }

        if(ch == 3){
            y=val.cursor_y=val.cursor_y-1;
        }

        if(val.cursor_x < 0){
            x=val.cursor_x = 0;
        }

        if(val.cursor_y < 0){
            y=val.cursor_y = 0;
        }

        if(val.cursor_x > val.m-1){
            x=val.cursor_x = val.m-1;
        }

        if(val.cursor_y > val.n-1){
            y=val.cursor_y = val.n-1;
        }
       
        print(val);
        
        refresh();
    }
    
    refresh();
    
    getch();
    
    endwin();
    
    return 0;
}

