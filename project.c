#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"print.h"
#include"utilities.h"
#include"core.h"

int main() {
    int m, n;
    int count,row,column;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);
    initialise(m, n); 
  /*  p=create_2D_array(m, n);
 
    randnum(p, m, n);

    print(p, m, n);
   
    same_numbers_row(p, m, n, &count, &row, &column);
       printf("same numbers found from %2d : %2d upto %2d : %2d\n",row, column, row, column+count-1);
    
    same_numbers_column(p, m, n, &count, &row, &column);
        printf("same numbers found from %2d : %2d upto %2d : %2d\n",row, column, row , column+count-1);
    */
    return 0;
}
