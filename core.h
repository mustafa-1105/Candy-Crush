
#ifndef CORE_H
#define CORE_H

struct values
{
    int **p;
    int m;
    int n;
    int cursor_x;
    int cursor_y;
    int score;
    int moves;
    int x,y;
    char direction;
};

int same_numbers_row(struct values val, int *count, int *row, int *column);

int same_numbers_column(struct values val, int *count, int *row, int *column);

int **initialize(struct values val);

void shifting_rows(struct values val, int x, int y, int shift);

void shifting_columns(struct values val, int x, int y, int shift);

int _switch(struct values val);

int reverse_switch(struct values val);

#endif
