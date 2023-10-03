#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int column;
    int value;
    struct Node *next;
} Node;
typedef struct RowNode
{
    int rowNumber;
    struct Node *row;
    struct RowNode *next;
} RowNode;

typedef struct Matrix
{
    int size;
    struct RowNode *head;
} Matrix;

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

void printTriples(struct Matrix *M)
{
    struct RowNode *temp = M->head;
    printf("M: ");
    while (temp->next != NULL)
    {
        while (temp->row->next != NULL)
        {

            if (temp->row->value != 0)
                printf("(%d,%d,%d) ", temp->rowNumber, temp->row->column, temp->row->value);
            temp->row = temp->row->next;
        }
        temp = temp->next;
    }
    printf("\n");
}

int readValue(struct Matrix *M, int row, int column)
{
    struct RowNode *temp = M->head;
    while (temp->rowNumber != row && temp != NULL)
    {
        temp = temp->next;
    }
    while (temp->row->column != column && temp->row != NULL)
    {
        temp->row = temp->row->next;
    }
    if (temp == NULL || temp->row == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("M[%d][%d] == %d\n", row, column, temp->row->value);
    }
}

int main(void)
{

    int isReading = 1;
    char letter;
    int row, column;
    int value;
    Matrix *M = NULL;
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
            else if (letter == 'p')
            {
                if (M != NULL)
                {
                    printTriples(M);
                }
            }
            else
            {
                isReading = 0;
                if (M != NULL)
                {
                    free(M);
                }
            }
        }
        else
        {
            printf("%d - %d - %d\n", row, column, value);
            if (letter == 'r')
            {
                readValue(M, row, column);
            }
            else
            {
                if (M != NULL)
                {
                }
            }
        }
    }
    return 0;
}
