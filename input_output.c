#include<curses.h>
#include "utilities.h"
#include "input_output.h"
#include "core.h"

char faces[][6] = {"0", "+", "#", "@", "*", "x"};

void print_banner(struct values val)
{
	attron(A_BOLD);

	attron(COLOR_PAIR(COLOR_RED));


	char line_1[] = "*****************************************";
	char line_2[] = "************** CANDY CRUSH **************";

	mvprintw(8, 41, "%s",line_1);

	mvprintw(9, 41, "%s",line_2);

	mvprintw(10, 41, "%s",line_1);

	mvprintw(12, 41, "    Score: %5d  ********  Moves: %2d",val.score, val.moves);

	attroff(COLOR_PAIR(COLOR_RED));

	attroff(A_BOLD);

}

void print(struct values val)
{
	print_banner(val);

	int **p = val.p;
	int i,j,k;

	int x1 = 53;

	attron(A_BOLD);

	attron(COLOR_PAIR(COLOR_RED));


	for(i = 11; i < 30; i++){

		mvprintw(i, 41, "*");

		mvprintw(i, 42, "*");

		mvprintw(i, 43, "*");

		mvprintw(i, 79, "*");

		mvprintw(i, 80, "*");

		mvprintw(i, 81, "*");
	}

	for(i = 41; i < 82; i++){

		mvprintw(28, i, "*");

		mvprintw(29, i, "*");

		mvprintw(30, i, "*");
	}

	attroff(COLOR_PAIR(COLOR_RED));

	attroff(A_BOLD);


	for(i = 0; i < val.m; i++) {

		int x = 53;

		for(j = 0; j < val.n; j++) {

			x = x+2;
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

int input(struct values val)
{
	if(val.x>0 && val.x<=val.m && val.y>0 && val.y<=val.n && (val.direction=='u' || val.direction=='d' || val.direction=='r' || val.direction=='l')){

		if(val.x==val.m && val.direction=='d'){

			return 0;
		}   else if(val.y==val.n && val.direction=='r'){

			return 0;
		}   else if(val.x==1 && val.direction=='u'){

			return 0;
		}   else if(val.y==1 && val.direction=='l'){

			return 0;
		}

		_switch(val);

		return 0;
	} 

	return 1;
}

int accept_input()
{
	char ch;

	if ((ch = getch()) == '\033') { // if the first value is esc

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
		// code for exit
	}
}

