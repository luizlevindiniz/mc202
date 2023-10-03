#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int column;
    int value;
    struct Node *next;
};
struct RowNode
{
    int rowNumber;
    struct Node *row;
    struct RowNode *next;
};

struct Matrix
{
    struct RowNode *head;
    int size;
};

struct RowNode *createRowNode()
{
    struct RowNode *rowNode = malloc(sizeof(struct RowNode));
    rowNode->next = NULL;
    rowNode->row = malloc(sizeof(struct Node));
    rowNode->rowNumber = 0;

    return rowNode;
}

struct Matrix *createMatrix()
{
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    if (matrix)
    {
        matrix->head = NULL;
        matrix->size = 0;
        return matrix;
    }
    else
    {
        return 0;
    }
}

int main(void)
{

    int isReading = 1;
    char letter;
    int row, column;
    int value;
    struct matrix *M = NULL;
    char line[20];

    while (isReading)
    {
        fgets(line, 20, stdin);

        if (sscanf(line, "%c [%d,%d] %d", &letter, &row, &column, &value) == 1)
        {
            if (letter == 'c')
            {
                if (M != NULL)
                {
                    free(M);
                }

                M = createMatrix();
            }
        }
        else
        {
            printf("%d - %d - %d\n", row, column, value);
        }
    }

    return 0;
}