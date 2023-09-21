#include <stdio.h>
#include <stdlib.h>

int isUnique(int **matrix, int rows, int columns, int row, int column)
{
    int isUnique = 0;
    if (row == 0)
    {
        if (column == 0)
        {
            if (matrix[row][column + 1] == '*' && matrix[row + 1][column] == '*' && matrix[row + 1][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column > 0 && column < columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row + 1][column - 1] == '*' &&
                matrix[row + 1][column] == '*' && matrix[row][column + 1] == '*' &&
                matrix[row + 1][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else
        {
            if (matrix[row][column - 1] == '*' && matrix[row + 1][column - 1] == '*' &&
                matrix[row + 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }
    }
    else if (row == rows - 1)
    {
        if (column == 0)
        {
            if (matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' && matrix[row][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column > 0 && column < columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' &&
                matrix[row][column + 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else
        {
            if (matrix[row][column - 1] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row - 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }
    }
    else
    {
        if (column == 0)
        {
            if (matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' &&
                matrix[row][column + 1] == '*' && matrix[row + 1][column + 1] == '*' && matrix[row + 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else if (column > 0 && column < columns - 1)
        {
            if (matrix[row][column - 1] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row - 1][column] == '*' && matrix[row - 1][column + 1] == '*' &&
                matrix[row][column + 1] == '*' && matrix[row + 1][column + 1] == '*' &&
                matrix[row + 1][column] == '*' && matrix[row + 1][column - 1] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
        }

        else
        {

            if (matrix[row - 1][column] == '*' && matrix[row - 1][column - 1] == '*' &&
                matrix[row][column - 1] == '*' && matrix[row + 1][column - 1] == '*' &&
                matrix[row + 1][column] == '*')
            {
                isUnique = 1;
                return isUnique;
            }
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
    scanf("%d %d", &rows, &columns);

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

                scanf(" %c ", &(oil[i][j]));
            }
        }
    }

    printMatrix(oil, rows, columns);

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
                else
                {
                    // if (isUnique(oil, rows, columns, i, j))
                    oilReserves++;
                }
            }
        }
    }
    printf("\n%d\n", oilReserves);

    for (int i = 0; i < rows; i++)
    {
        free(oil[i]);
    }
    free(oil);
    scanf("%d %d ", &rows, &columns);

    return 0;
}