#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include "utilities.h"

#define BLACK "\033[030m"
#define RED "\033[031m"
#define GREEN "\033[032m"
#define YELLOW "\033[033m"
#define BLUE "\033[034m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"


void print(int **p, int m, int n)
{
    setlocale(LC_ALL, "");
    int i,j,k;
    wprintf(L"     ");
    for(i=0; i<n; i++){
        wprintf(L"%d ",i+1);
    }

    wprintf(L"\n     ");
    for(i=0; i<n; i++){
        wprintf(L"--");
    }
    wprintf(L"\n");
    for(i = 0; i < m; i++) {
        wprintf(L"%2d | ",i+1);
        for(j = 0; j < n; j++) {
            switch (p[i][j]) {
                case 0:
                    wprintf("\033[031m"L"%ls", L"\x2764""\033[0m ");
                    break;
                case 1:
                    wprintf("\033[032m"L"%ls", L"\x2605""\033[0m ");
                    break;
                case 2:
                    wprintf("\033[033m"L"%ls", L"\x262f""\033[0m ");
                    break;
                case 3:
                    wprintf("\033[030m"L"%ls", L"\x2663""\033[0m ");
                    break;
                case 4:
                    wprintf("\033[035m"L"%ls", L"\x271a""\033[0m ");
                    break;
                case 5:
                    wprintf("\033[036m"L"%ls", L"\x2731""\033[0m ");
                    break;
            }
        }
        wprintf(L"\n");
    }
}

