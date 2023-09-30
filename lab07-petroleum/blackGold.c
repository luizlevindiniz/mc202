#include <stdio.h>
#include <stdlib.h>

void isUnique(int **matrix, int rows, int columns, int row, int column, int *oilReserveNumber)
{

    if (rows == 1 && columns == 1)
    {
        matrix[row][column] = *oilReserveNumber;
    }
    else if (rows == 1)
    {
        if (column == 0)
        {

            *oilReserveNumber = *oilReserveNumber + 1;
            matrix[row][column] = *oilReserveNumber;

            if (matrix[row][column + 1] == -1)
            {

                matrix[row][column + 1] = *oilReserveNumber;
            }
        }
        else if (column == columns - 1)
        {
            if (matrix[row][column - 1] == 0)
            {
                *oilReserveNumber = *oilReserveNumber + 1;
                matrix[row][column] = *oilReserveNumber;
            }
            else if (matrix[row][column - 1] > 0)
            {
                matrix[row][column] = matrix[row][column - 1];
            }
        }
        else
        {
            if (matrix[row][column + 1] == 0 && matrix[row][column - 1] == 0)
            {
                *oilReserveNumber = *oilReserveNumber + 1;
                matrix[row][column] = *oilReserveNumber;
            }
            else if (matrix[row][column - 1] > 0)
            {
                matrix[row][column] = matrix[row][column - 1];
            }
            else
            {
                *oilReserveNumber = *oilReserveNumber + 1;
                matrix[row][column] = *oilReserveNumber;
                matrix[row][column - 1] = *oilReserveNumber;
            }
        }
    }
    else if (columns == 1)
    {
        if (row == 0)
        {
            *oilReserveNumber = *oilReserveNumber + 1;
            matrix[row][column] = *oilReserveNumber;

            if (matrix[row + 1][column] == -1)
            {

                matrix[row + 1][column] = *oilReserveNumber;
            }
        }
        else if (row == rows - 1)
        {
            if (matrix[row + 1][column] == 0)
            {
                *oilReserveNumber = *oilReserveNumber + 1;
                matrix[row][column] = *oilReserveNumber;
            }
            else if (matrix[row + 1][column] > 0)
            {

                matrix[row][column] = matrix[row + 1][column];
            }
        }
        else
        {
            if (matrix[row + 1][column] == 0 && matrix[row - 1][column] == 0)
            {
                *oilReserveNumber = *oilReserveNumber + 1;
                matrix[row][column] = *oilReserveNumber;
            }
            else if (matrix[row - 1][column] > 0)
            {
                matrix[row][column] = matrix[row - 1][column];
            }
            else
            {
                *oilReserveNumber = *oilReserveNumber + 1;
                matrix[row][column] = *oilReserveNumber;
                matrix[row - 1][column] = *oilReserveNumber;
            }
        }
    }

    else
    {
        if (row == 0)
        {
            if (column == 0)
            {
                if (matrix[row][column + 1] == 0 && matrix[row + 1][column] == 0 && matrix[row + 1][column + 1] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row][column + 1];
                }
                else if (matrix[row + 1][column] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column];
                }
                else if (matrix[row + 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column + 1];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row][column + 1] == -1)
                    {
                        matrix[row][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column] == -1)
                    {
                        matrix[row + 1][column] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column + 1] == -1)
                    {
                        matrix[row + 1][column + 1] = *oilReserveNumber;
                    }

                    matrix[row][column] = *oilReserveNumber;
                }
            }

            else if (column == columns - 1)
            {
                if (matrix[row][column - 1] == 0 && matrix[row + 1][column - 1] == 0 &&
                    matrix[row + 1][column] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row][column - 1];
                }
                else if (matrix[row + 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column - 1];
                }
                else if (matrix[row + 1][column] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row][column - 1] == -1)
                    {
                        matrix[row][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column - 1] == -1)
                    {
                        matrix[row + 1][column - 1] = *oilReserveNumber;
                    }

                    if (matrix[row + 1][column] == -1)
                    {
                        matrix[row + 1][column] = *oilReserveNumber;
                    }

                    matrix[row][column] = *oilReserveNumber;
                }
            }
            else if (column > 0 && column < columns - 1)
            {
                if (matrix[row][column - 1] == 0 && matrix[row + 1][column - 1] == 0 &&
                    matrix[row + 1][column] == 0 && matrix[row][column + 1] == 0 &&
                    matrix[row + 1][column + 1] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row][column - 1];
                }
                else if (matrix[row + 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column - 1];
                }
                else if (matrix[row + 1][column] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column];
                }
                else if (matrix[row][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row][column + 1];
                }
                else if (matrix[row + 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column + 1];
                }
                else
                {
                    // add cases
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row + 1][column - 1] == -1)
                    {
                        matrix[row + 1][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column + 1] == -1)
                    {
                        matrix[row + 1][column + 1] = *oilReserveNumber;
                    }
                    matrix[row][column] = *oilReserveNumber;
                }
            }
        }

        else if (row == rows - 1)
        {
            if (column == 0)
            {
                if (matrix[row - 1][column] == 0 && matrix[row - 1][column + 1] == 0 && matrix[row][column + 1] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row - 1][column] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column];
                }
                else if (matrix[row - 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column + 1];
                }
                else if (matrix[row][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row][column + 1];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row - 1][column] == -1)
                    {
                        matrix[row - 1][column] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column + 1] == -1)
                    {
                        matrix[row - 1][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row][column + 1] == -1)
                    {
                        matrix[row][column + 1] = *oilReserveNumber;
                    }

                    matrix[row][column] = *oilReserveNumber;
                }
            }

            else if (column == columns - 1)
            {
                if (matrix[row][column - 1] == 0 && matrix[row - 1][column - 1] == 0 &&
                    matrix[row - 1][column] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row][column - 1];
                }
                else if (matrix[row - 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column - 1];
                }
                else if (matrix[row - 1][column] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row][column - 1] == -1)
                    {
                        matrix[row][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column - 1] == -1)
                    {
                        matrix[row - 1][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column] == -1)
                    {
                        matrix[row - 1][column] = *oilReserveNumber;
                    }

                    matrix[row][column] = *oilReserveNumber;
                }
            }
            else if (column > 0 && column < columns - 1)
            {
                if (matrix[row][column - 1] == 0 && matrix[row - 1][column - 1] == 0 &&
                    matrix[row - 1][column] == 0 && matrix[row - 1][column + 1] == 0 &&
                    matrix[row][column + 1] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row][column - 1];
                }
                else if (matrix[row - 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column - 1];
                }
                else if (matrix[row - 1][column] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column];
                }
                else if (matrix[row - 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column + 1];
                }
                else if (matrix[row][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row][column + 1];
                }
                else
                {
                    // add cases
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row - 1][column - 1] == -1)
                    {
                        matrix[row - 1][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column + 1] == -1)
                    {
                        matrix[row - 1][column + 1] = *oilReserveNumber;
                    }
                    matrix[row][column] = *oilReserveNumber;
                }
            }
        }

        else
        {
            if (column == 0)
            {
                if (matrix[row - 1][column] == 0 && matrix[row - 1][column + 1] == 0 &&
                    matrix[row][column + 1] == 0 && matrix[row + 1][column + 1] == 0 && matrix[row + 1][column] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row - 1][column] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column];
                }
                else if (matrix[row - 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column + 1];
                }
                else if (matrix[row][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row][column + 1];
                }
                else if (matrix[row + 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column + 1];
                }
                else if (matrix[row + 1][column] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row - 1][column] == -1)
                    {
                        matrix[row - 1][column] = *oilReserveNumber;
                    }

                    if (matrix[row - 1][column + 1] == -1)
                    {
                        matrix[row - 1][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row][column + 1] == -1)
                    {
                        matrix[row][column + 1] = *oilReserveNumber;
                    }

                    if (matrix[row + 1][column + 1] == -1)
                    {
                        matrix[row + 1][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column] == -1)
                    {
                        matrix[row + 1][column] = *oilReserveNumber;
                    }
                    matrix[row][column] = *oilReserveNumber;
                }
            }

            else if (column == columns - 1)
            {

                if (matrix[row - 1][column] == 0 && matrix[row - 1][column - 1] == 0 &&
                    matrix[row][column - 1] == 0 && matrix[row + 1][column - 1] == 0 &&
                    matrix[row + 1][column] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row - 1][column] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column];
                }
                else if (matrix[row - 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column - 1];
                }
                else if (matrix[row][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row][column - 1];
                }
                else if (matrix[row + 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column - 1];
                }
                else if (matrix[row + 1][column] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;

                    if (matrix[row - 1][column] == -1)
                    {
                        matrix[row - 1][column] = *oilReserveNumber;
                    }

                    if (matrix[row - 1][column - 1] == -1)
                    {
                        matrix[row - 1][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row][column - 1] == -1)
                    {
                        matrix[row][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column - 1] == -1)
                    {
                        matrix[row + 1][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column] == -1)
                    {
                        matrix[row + 1][column] = *oilReserveNumber;
                    }

                    matrix[row][column] = *oilReserveNumber;
                }
            }
            else if (column > 0 && column < columns - 1)
            {
                if (matrix[row][column - 1] == 0 && matrix[row - 1][column - 1] == 0 &&
                    matrix[row - 1][column] == 0 && matrix[row - 1][column + 1] == 0 &&
                    matrix[row][column + 1] == 0 && matrix[row + 1][column + 1] == 0 &&
                    matrix[row + 1][column] == 0 && matrix[row + 1][column - 1] == 0)
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    matrix[row][column] = *oilReserveNumber;
                }
                else if (matrix[row][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row][column - 1];
                }
                else if (matrix[row - 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column - 1];
                }
                else if (matrix[row - 1][column] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column];
                }
                else if (matrix[row - 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row - 1][column + 1];
                }
                else if (matrix[row][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row][column + 1];
                }
                else if (matrix[row + 1][column + 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column + 1];
                }
                else if (matrix[row + 1][column] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column];
                }
                else if (matrix[row + 1][column - 1] > 0)
                {

                    matrix[row][column] = matrix[row + 1][column - 1];
                }
                else
                {
                    *oilReserveNumber = *oilReserveNumber + 1;
                    if (matrix[row][column - 1] == -1)
                    {
                        matrix[row][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column - 1] == -1)
                    {
                        matrix[row - 1][column - 1] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column] == -1)
                    {
                        matrix[row - 1][column] = *oilReserveNumber;
                    }
                    if (matrix[row][column + 1] == -1)
                    {
                        matrix[row][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column] == -1)
                    {
                        matrix[row + 1][column] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column + 1] == -1)
                    {
                        matrix[row + 1][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row - 1][column + 1] == -1)
                    {
                        matrix[row - 1][column + 1] = *oilReserveNumber;
                    }
                    if (matrix[row + 1][column - 1] == -1)
                    {
                        matrix[row + 1][column - 1] = *oilReserveNumber;
                    }

                    matrix[row][column] = *oilReserveNumber;
                }
            }
        }
    }

    return;
}

void printMatrix(int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d", matrix[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

int main()
{
    int rows = 0, columns = 0;
    int keepReading = 1;

    while (keepReading)
    {
        // scanf rows,columns until columns = 0
        scanf("%d %d", &rows, &columns);
        if (columns == 0)
        {
            keepReading = 0;
        }
        else
        {

            int oilReserveNumber = 0;
            // 2D array memory alloc. 2DArray size (rows x columns)
            int **oil = (int **)malloc(rows * sizeof(int *));
            char value;
            if (oil)
            // in case of success
            {
                for (int i = 0; i < rows; i++)
                {

                    oil[i] = (int *)malloc(columns * sizeof(int));

                    for (int j = 0; j < columns; j++)
                    {
                        // read @ or *

                        scanf(" %c", &value);

                        // no need to change * to 0 and @ to -1
                        // just to make it look like a binary 2D
                        // array

                        if (value == '*')
                        {
                            (oil[i][j]) = 0;
                        }
                        else
                        {

                            (oil[i][j]) = -1;
                        }
                    }
                }
            }

            // loop through the array checking if a given element has neighbors
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (oil[i][j] == -1)
                    {
                        isUnique(oil, rows, columns, i, j, &oilReserveNumber);
                    }
                }
            }

            printf("%d\n", oilReserveNumber);
            // 2D array dealloc.
            for (int i = 0; i < rows; i++)
            {
                free(oil[i]);
            }
            free(oil);
        }
    }

    return 0;
}