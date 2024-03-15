#include<stdio.h>
#include<stdbool.h>
#define N 9

void printSudoku(int sudoku[N][N])
{
for (int row = 0; row < N; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            printf("-----------\n");
        }
        for (int column = 0; column < N; column++)
        {
            if (column % 3 == 0 && column != 0)
            {
                printf("|");
            }
            printf("%d", sudoku[row][column]);
        }
        printf("\n");
    }

}
bool checkRow(int sudoku[N][N] , int number , int row)
{
    for (int i = 0; i < 9; i++)
    {
        if(sudoku[row][i] == number)
        {
            return true;
        }
    }
    
    return false;
    
}
bool checkColumn(int sudoku[N][N] , int number , int column)
{
    for(int i = 0 ; i < N ; i++)
    {
        if(sudoku[i][column] == number)
        {
            return true;
        }
    }
    return false;
}
bool checkGrid(int sudoku[N][N] , int row ,int  column , int number)
{
    int rowOfBox = row - row%3;
   int columnOfBox = column - column%3;
    for (int i = rowOfBox; i < rowOfBox + 3; i++)
    {
        for (int j = columnOfBox; j < columnOfBox + 3; j++)
        {
            if(sudoku[i][j] == number)
            {
                return true;
            }
        }
        
    }
    return false;
}

bool isNumberValid(int sudoku[N][N] , int number , int row , int column)
{
    return (!checkRow(sudoku , number , row) && !checkColumn(sudoku, number, column) && !checkGrid(sudoku, row, column ,number));
    
}
bool solveSudoku(int sudoku[N][N])
{
    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(sudoku[i][j] == 0)
            {
                for(int number = 1 ;number <=N ; number++)
            {
            if(isNumberValid(sudoku , number , i , j))
                {
                    sudoku[i][j] = number;
                    if (solveSudoku(sudoku))
                    {
                        return true;
                    }
                    else
                    {
                        sudoku[i][j] = 0;
                    }
                    
                }
            }
            return false;
            }
        }
        
    }
    
return true;
}

int main(){
    int sudoku[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
    // int sudoku[N][N] = {0};
// for (int i = 0; i < N; i++)
// {
//     for (int j = 0; j < N; j++)
//     {
//     printf("Enter the value of:[%d][%d]" , i+1 , j+1);
//     scanf("%d" , sudoku[i][j]);
//     }
    
// }

    printSudoku(sudoku);

    if (solveSudoku(sudoku))
    {
        printf("\n\nSolved Sudoku:\n\n\n");
        printSudoku(sudoku);
    }
    else
    {
        printf("Sudoku can't be solved");
    }
    return 0;

}