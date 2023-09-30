/**
 * Program to check the number of unique oil reserves in a given grid.
 *
 * Info:
 * A grid has a rectangular/square shape.
 * An oil field is represented by a @ and empty spaces are represented by *
 *
 * If two oil fields are adjacent (vertically, horizontally or diagonally)
 * then they belong to the same oil reserve.
 *
 * Input: a grid (row x columns), where (rows,columns) belongs to
 * [0, ... , 10000] interval. If columns = 0, the input has ended.
 *
 * Output: the number of grid's unique oil reserves

    (examples)
    3 5
    *@*@*
    **@**
    *@*@*
    output: 1 (all @ take part in the same oil reserve)

    1 8
    @@****@*
    output: 2 (2 unique oil reserves)

 * Authors: Luiz Felipe Diniz
 * Last Modified: 24/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

// temporary function
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

            char valueRead;
            int oilReserveNumber = 0;
            // 2D array memory alloc. 2DArray size (rows x columns)
            int **oil = (int **)malloc(rows * sizeof(int *));

            // in case of success
            if (oil)
            {
                for (int i = 0; i < rows; i++)
                {

                    oil[i] = (int *)malloc(columns * sizeof(int));

                    for (int j = 0; j < columns; j++)
                    {
                        // read @ or *
                        scanf(" %c", &valueRead);

                        // no need to change * to 0 and @ to 1
                        // just to make it look like a binary 2D
                        // array

                        if (valueRead == '*')
                        {
                            (oil[i][j]) = 0;
                        }
                        else
                        {

                            (oil[i][j]) = 1;
                        }
                    }
                }
            }

            // no need to print, just to check if everything went fine
            printMatrix(oil, rows, columns);

            // loop through the array checking if a given element has neighbors
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (oil[i][j] == 1)
                    {
                        // do something
                    }
                }
            }

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