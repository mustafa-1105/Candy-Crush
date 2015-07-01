
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
    int x,y;
    char direction;
};

int same_numbers_row(int **p, int m, int n, int *count, int *row, int *column);
int same_numbers_column(int **p, int m, int n, int *count, int *row, int *column);
int **initialize(int m, int n);
void shifting_rows(int **p, int m, int n, int x, int y, int shift);
void shifting_columns(int **p, int m, int n, int x, int y, int shift);
int _switch(struct values val, int x, int y, char direction);
int reverse_switch(int **p, int m, int n, int x, int y, char direction);

#endif
