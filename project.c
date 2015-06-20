#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"print.h"
#include"utilities.h"
#include"core.h"

int main() {
    int **p;
    int m, n;
    int count,row,column;
    scanf("%d%d", &m, &n);
    initialize(p, m, n); 
    return 0;
}
