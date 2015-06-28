#include<ncurses.h>
#include<unistd.h>
#include <stdlib.h>
#include <time.h>
#include"input_output.h"
#include"utilities.h"
#include"core.h"

#define ROWS 10
#define COLS 7

int main(int argc, char *argv[]) 
{    
    struct values val;
    int i;
    val.m = ROWS;
    val.n = COLS;
    val.cursor_x = 2;
    val.cursor_y = 3;

    int count,row,column,x,y;

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
    
    print(val);
    
    refresh();
    getch();
    endwin();
    return 0;
}
