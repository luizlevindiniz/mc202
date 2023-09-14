#include <stdio.h>
#include <stdlib.h>

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

    int rows = 0, columns = 0;
    scanf("%d %d ", &rows, &columns);

    while (columns != 0)
    {

        int **oil = malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++)
        {
            /* code */
            oil[i] = malloc(columns * sizeof(int));
        }
        char *line = malloc(sizeof(char) * columns);

        for (int i = 0; i < rows; i++)
        {
            scanf("%[^\n]%*c ", line);
            for (int j = 0; j < columns; j++)
            {

                oil[i][j] = line[j];
            }
        }
        printMatrix(oil, rows, columns);

        for (int i = 0; i < rows; i++)
        {
            free(oil[i]);
        }
        free(oil);
        free(line);
        scanf("%d %d ", &rows, &columns);
    }

    return 0;
}