#include <stdio.h>

void printSudoku();
int solveSudoku(int, int);
int sameColumn(int, int, int);
int sameRow(int, int, int);
int sameSquare(int, int, int);

int sudoku[9][9] = {     {0,0,4,0,5,0,0,0,0},
                                       {9,0,0,7,3,4,6,0,0},
                                       {0,0,3,0,2,1,0,4,9},
                                       {0,3,5,0,9,0,4,8,0},
                                       {0,9,0,0,0,0,0,3,0},
                                       {0,7,6,0,1,0,9,2,0},
                                       {3,1,0,9,7,0,2,0,0},
                                       {0,0,9,1,8,2,0,0,3},
                                       {0,0,0,0,6,0,1,0,0}
                                       
                                       };

int main() {
    int x=0, y=0;
    
    printf("  Before: \n\n");
    printSudoku();
    printf("  _______\n\n");
    solveSudoku(x, y);
    printSudoku();
    printf("  DONE :)\n\n");
    
    return 0;
}


void printSudoku() {
    int i, j;
    for (i=0; i<9; i++) {
        for (j=0; j<9; j++) {
            printf("  %d", sudoku[i][j]);
            !((j+1)%3) ? printf("    ") : printf("");
        }
        printf("\n");
        !((i+1)%3) ? printf("\n") : printf("");
    }
    printf("\n");
}

int solveSudoku(int x, int y) {
    int n=1;
    int tx=0, ty=0;
    
    if (sudoku[x][y] != 0) {
        if (x==8 && y==8) return 1;
        if (x<8) x++;
        else {
            x=0;
            y++;
        }
        
        if (solveSudoku(x, y)) return 1;
        return 0;
    }
    
    
    if (sudoku[x][y] == 0) {
        while (n<10) {
              if (!sameSquare(x,y,n) &&                                                !sameColumn(x,y,n) &&
                   !sameRow(x,y,n) ) {
                   sudoku[x][y] = n;
                   if (x==8 && y==8) return 1;
                   if (x<8) tx = x+1;
                   else {
                          if (y<8) {
                                tx=0;
                                ty = y+1;
                          }
                   }
                   
                   if (solveSudoku(tx, ty)) return 1;
              }
              n++;
        }
        sudoku[x][y] = 0;
        return 0;
    }
    
}

int sameColumn(int x, int y, int n) {
    int j;
    for (j=0; j<9; j++) {
        if (sudoku[x][j] == n) return 1;
    }
    return 0;
}

int sameRow(int x, int y, int n) {
    int i;
    for (i=0; i<9; i++) {
        if (sudoku[i][y] == n) return 1;
    }
    return 0;
}

int sameSquare(int x, int y, int n) {
    int i, j;
    if (x<3) x=0;
    else if (x<6) x=3;
    else x=6;
    
    if (y<3) y=0;
    else if (y<6) y=3;
    else y=6;
    
    for (i=x; i<x+3; i++) {
        for (j=y; j<y+3; j++) {
            if (sudoku[i][j] == n) return 1;
        }
    }
    return 0;
}
