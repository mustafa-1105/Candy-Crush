#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *create_2D_array();
int randnum();
void print();
int main() {
    int **p;
    int m, n,i,j;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);
    create_2D_array(&*p, m,n);

   /* srand(time(NULL));
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            p[i][j] = rand() % 9;
        }
    }*/
    print(p, m, n);
    return 0;
}

int *create_2D_array(int **s,int m, int n)
{
    int **p;
    int x,y,i;
    p = (int **) malloc(x * sizeof(int *)); 
    for(i = 0; i < m; i++) {
        p[i] = (int *) malloc(y * sizeof(int)); 
    }
    return (&p);


};
int randnum(){};
void print(int **p, int m,int n)
{
    int i,j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");

    }



}
