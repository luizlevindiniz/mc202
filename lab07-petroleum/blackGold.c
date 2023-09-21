#include <stdio.h>
#include <stdlib.h>

int isUnique(int **matrix, int rows, int columns, int row, int column)
{
    int isUnique = 0;
    if (rows == 1 && columns == 1)
    {
        isUnique = 1;
    }
    else if (rows == 1)
    {
        if (column == 0 && matrix[row][column + 1] == '*')
        {
            isUnique = 1;
        }
        else if (column == columns - 1 && matrix[row][column - 1] == '*')
        {
            isUnique = 1;
        }
        else if (matrix[row][column + 1] == '*' && matrix[row][column - 1] == '*')
        {
            isUnique = 1;
        }
    }
    else if (columns == 1)
    {
        if (row == 0 && matrix[row + 1][column] == '*')
        {
            isUnique = 1;
        }
        else if (row == rows - 1 && matrix[row + 1][column] == '*')
        {
            isUnique = 1;
        }
        else if (matrix[row + 1][column] == '*' && matrix[row - 1][column] == '*')
        {
            isUnique = 1;
        }
    }
    return isUnique;
}

void printMatrix(int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%c", matrix[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int oilReserves;
    int rows = 0, columns = 0;
    int keepReading = 1;

    while (keepReading)
    {
        scanf("%d %d", &rows, &columns);
        if (columns == 0)
        {
            keepReading = 0;
        }
        else
        {

            oilReserves = 0;
            int **oil = (int **)malloc(rows * sizeof(int *));
            if (oil)
            {
                for (int i = 0; i < rows; i++)
                {
                    /* code */
                    oil[i] = (int *)malloc(columns * sizeof(int));

                    for (int j = 0; j < columns; j++)
                    {

                        scanf(" %c", &(oil[i][j]));
                    }
                }
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (oil[i][j] == '@')
                    {

                        if (oilReserves == 0)
                        {
                            oilReserves++;
                        }
                        else if (isUnique(oil, rows, columns, i, j))
                        {

                            oilReserves++;
                        }
                    }
                }
            }
            printf("%d\n", oilReserves);

            for (int i = 0; i < rows; i++)
            {
                free(oil[i]);
            }
            free(oil);
        }
    }

    return 0;
}