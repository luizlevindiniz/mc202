/* Implementation of a list of lists using a 2D dynamic array

Author: Luiz Diniz
Last Update: 09/10/2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a node to store column and value
typedef struct Node
{
    int column;
    int value;
    struct Node *next;
} Node;
// an entire row, tagged with a row number
typedef struct RowNode
{
    int rowNumber;
    struct Node *row;
    struct RowNode *next;
} RowNode;

// head to the first row a.k.a pointer to matrix beggining
typedef struct Matrix
{
    struct RowNode *head;
} Matrix;

// function to create a new Row, tagget with a given row number
RowNode *createRowNode(int rowNumber)
{
    RowNode *rowNode = malloc(sizeof(RowNode));
    if (rowNode)
    {

        rowNode->next = NULL;
        rowNode->row = NULL;
        rowNode->rowNumber = rowNumber;

        return rowNode;
    }
    else
    {
        return NULL;
    }
}

// function to create an empty matrix, in failure returns NULL
Matrix *createMatrix()
{
    Matrix *matrix = malloc(sizeof(Matrix));
    if (matrix)
    {
        matrix->head = NULL;
        return matrix;
    }
    else
    {
        return NULL;
    }
}

// function to print (row, column, value) for each element in matrix where value != 0
void printTriples(Matrix *M)
{
    if (M->head != NULL)
    {
        RowNode *temp = M->head;
        Node *check = NULL;
        int count = 0;
        while (temp != NULL)
        {
            check = temp->row;
            if (check)
            {
                while (check != NULL)
                {
                    if (check->value != 0)
                    {
                        if (count == 0)
                        {
                            printf("M: ");
                            count++;
                        }
                        printf("(%d,%d,%d) ", temp->rowNumber, check->column, check->value);
                    }
                    check = check->next;
                }
                temp = temp->next;
            }
        }
        if (count == 0)
        {
            printf("A matriz e' nula.\n");
        }
        else
        {
            printf("\n");
        }
    }
    else
    {
        printf("A matriz e' nula.\n");
    }
}

// function to read a value in matrix, with a given row and column
int readValue(Matrix *M, int row, int column)
{
    if (M)
    {

        RowNode *temp = M->head;
        Node *check = NULL;
        while (temp != NULL && temp->rowNumber != row)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            check = temp->row;
            while (check != NULL && check->column != column)
            {
                check = check->next;
            }
        }

        if (temp == NULL || check == NULL)
        {
            printf("M[%d][%d] == 0\n", row, column);

            return 0;
        }

        else
        {
            printf("M[%d][%d] == %d\n", row, column, check->value);

            return (check->value);
        }
    }
    else
    {
        return 0;
    }
}

void freeRows(Node *rowHead)
{
    Node *temp = rowHead;
    while (rowHead != NULL)
    {
        rowHead = rowHead->next;
        free(temp);
        temp = rowHead;
    }
}

void freeRowNodes(RowNode *rowNodeHead)
{
    RowNode *temp = rowNodeHead;

    while (rowNodeHead != NULL)
    {
        rowNodeHead = rowNodeHead->next;
        free(temp);
        temp = rowNodeHead;
    }
}

int main(void)
{

    int isReading = 1;
    char letter;
    int row, column;
    int value;
    Matrix *M = NULL;
    char line[40];

    while (isReading)
    {
        fgets(line, 40, stdin);

        if (sscanf(line, "%c [%d,%d] %d", &letter, &row, &column, &value) == 1)
        {
            if (letter == 'c')
            {
                if (M)
                {
                    RowNode *deleteRowNode = M->head;
                    while (deleteRowNode)
                    {
                        Node *deleteRow = deleteRowNode->row;
                        if (deleteRow)
                        {
                            freeRows(deleteRow);
                        }
                        deleteRowNode = deleteRowNode->next;
                    }
                    freeRowNodes(deleteRowNode);
                    free(M);
                }

                M = createMatrix();
            }
            else if (letter == 'p')
            {
                if (M)
                {
                    printTriples(M);
                }
            }
            else
            {
                isReading = 0;
                if (M)
                {
                    RowNode *deleteRowNode = M->head;
                    while (deleteRowNode)
                    {
                        Node *deleteRow = deleteRowNode->row;
                        if (deleteRow)
                        {
                            freeRows(deleteRow);
                        }
                        deleteRowNode = deleteRowNode->next;
                    }
                    freeRowNodes(deleteRowNode);
                    free(M);
                }
            }
        }
        else
        {

            if (letter == 'r')
            {
                // printf("r %d - %d - %d\n", row, column, value);
                readValue(M, row, column);
            }
            else
            {
                if (M)
                {
                    // printf("a %d - %d - %d\n", row, column, value);
                    if (M->head == NULL)
                    {
                        RowNode *newRow = createRowNode(row);
                        Node *newNode = malloc(sizeof(Node));
                        newNode->next = NULL;
                        newNode->column = column;
                        newNode->value = value;

                        M->head = newRow;
                        newRow->row = newNode;
                    }
                    else
                    {
                        RowNode *temp = M->head;
                        if (temp->rowNumber > row)
                        {
                            RowNode *newRow = createRowNode(row);
                            Node *newNode = malloc(sizeof(Node));
                            newNode->next = NULL;
                            newNode->column = column;
                            newNode->value = value;

                            M->head = newRow;
                            newRow->row = newNode;
                            newRow->next = temp;
                        }
                        else
                        {
                            int isLooping = 1;
                            while (temp->next != NULL && isLooping)
                            {
                                if (temp->rowNumber == row)
                                {
                                    Node *checkHead = temp->row;
                                    Node *checkNext = temp->row->next;
                                    Node *newNode = malloc(sizeof(Node));
                                    newNode->column = column;
                                    newNode->value = value;
                                    newNode->next = NULL;

                                    if (checkHead->column > newNode->column)
                                    {
                                        newNode->next = checkHead;
                                        temp->row = newNode;
                                    }
                                    else
                                    {
                                        int isReading = 1;
                                        while (isReading)
                                        {
                                            if (checkNext == NULL)
                                            {
                                                if (checkHead->column == newNode->column)
                                                {
                                                    checkHead->value = newNode->value;
                                                    isReading = 0;
                                                }
                                                else
                                                {
                                                    checkHead->next = newNode;
                                                    isReading = 0;
                                                }
                                            }
                                            else
                                            {
                                                if (checkHead->column == newNode->column)
                                                {
                                                    checkHead->value = newNode->value;
                                                    isReading = 0;
                                                }
                                                else if (checkHead->column < newNode->column && checkNext->column > newNode->column)
                                                {
                                                    checkHead->next = newNode;
                                                    newNode->next = checkNext;
                                                    isReading = 0;
                                                }
                                                else
                                                {

                                                    checkHead = checkHead->next;
                                                    checkNext = checkNext->next;
                                                }
                                            }
                                        }
                                    }
                                    isLooping = 0;
                                }
                                else if (temp->next->rowNumber > row)
                                {
                                    RowNode *newRow = createRowNode(row);
                                    Node *newNode = malloc(sizeof(Node));
                                    newNode->next = NULL;
                                    newNode->column = column;
                                    newNode->value = value;

                                    newRow->row = newNode;
                                    newRow->next = temp->next;
                                    temp->next = newRow;
                                    isLooping = 0;
                                }
                                else
                                {
                                    temp = temp->next;
                                }
                            }
                            if (temp->next == NULL)
                            {

                                if (temp->rowNumber != row)
                                {

                                    RowNode *newRow = createRowNode(row);
                                    Node *newNode = malloc(sizeof(Node));
                                    newNode->next = NULL;
                                    newNode->column = column;
                                    newNode->value = value;

                                    temp->next = newRow;
                                    newRow->row = newNode;
                                }
                                else
                                {
                                    Node *checkHead = temp->row;
                                    Node *checkNext = temp->row->next;
                                    Node *newNode = malloc(sizeof(Node));
                                    newNode->column = column;
                                    newNode->value = value;
                                    newNode->next = NULL;

                                    if (checkHead->column > newNode->column)
                                    {
                                        newNode->next = checkHead;
                                        temp->row = newNode;
                                    }
                                    else
                                    {
                                        int isReading = 1;
                                        while (isReading)
                                        {
                                            if (checkNext == NULL)
                                            {
                                                if (checkHead->column == newNode->column)
                                                {
                                                    checkHead->value = newNode->value;
                                                    isReading = 0;
                                                }
                                                else
                                                {
                                                    checkHead->next = newNode;
                                                    isReading = 0;
                                                }
                                            }
                                            else
                                            {
                                                if (checkHead->column == newNode->column)
                                                {
                                                    checkHead->value = newNode->value;
                                                    isReading = 0;
                                                }
                                                else if (checkHead->column < newNode->column && checkNext->column > newNode->column)
                                                {
                                                    checkHead->next = newNode;
                                                    newNode->next = checkNext;
                                                    isReading = 0;
                                                }
                                                else
                                                {

                                                    checkHead = checkHead->next;
                                                    checkNext = checkNext->next;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    printf("A matriz e' nula.\n");
                }
            }
        }
    }
    return 0;
}
