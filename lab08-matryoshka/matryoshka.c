#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    /* data */
    int top;
    int maxSize;
    int *stackArray;
};

struct Stack *createMatryoshka(int maxSize)
{
    struct Stack *matryoshka = malloc(sizeof(struct Stack));
    matryoshka->top = -1;
    matryoshka->maxSize = maxSize;
    matryoshka->stackArray = malloc(sizeof(int) * maxSize);

    return matryoshka;
}

int isFull(struct Stack *matryoshka)
{
    return matryoshka->maxSize == matryoshka->top + 1;
}
int isEmpty(struct Stack *matryoshka)
{
    return matryoshka->top == -1;
}

int topValue(struct Stack *matryoshka)
{
    if (!isEmpty(matryoshka))
    {

        return ((matryoshka->stackArray)[matryoshka->top]);
    }

    else
    {
        return -1;
    }
}

void push(struct Stack *matryoshka, int doll)
{
    if (!isFull(matryoshka))
    {
        matryoshka->top = matryoshka->top + 1;
        matryoshka->stackArray[matryoshka->top] = doll;
    }
    return;
}

int pop(struct Stack *matryoshka)
{
    if (!isEmpty(matryoshka))
    {
        int item = matryoshka->stackArray[matryoshka->top];
        matryoshka->top = matryoshka->top - 1;
        return item;
    }
    int empty = isEmpty(matryoshka);
    return empty;
}

void printMatryoshka(struct Stack *matryoshka)
{
    for (int i = 0; i <= matryoshka->top; i++)
    {
        printf("%d ", matryoshka->stackArray[i]);
    }
    printf("\n");
}

int main(void)
{
    int dollSize = 1;

    while (dollSize > 0)
    {

        scanf("%d", &dollSize);

        struct Stack *matryoshka = createMatryoshka(dollSize);
        int *aux = malloc(sizeof(int) * dollSize);
        int isMatryoshka = 1;
        int doll = 0;
        int lastElement = 0;
        int actualSize = 0;
        for (int i = 0; i < dollSize; i++)
        {
            scanf("%d", &aux[i]);
            // printf("%d ", aux[i]);
        }
        for (int i = 0; i < dollSize; i++)
        {
            doll = aux[i];
            if (doll < 0)
            {

                if (i == 0)
                {
                    actualSize++;
                    push(matryoshka, doll);
                }
                else
                {
                    lastElement = topValue(matryoshka);
                    if (lastElement > doll)
                    {
                        isMatryoshka = 0;
                        break;
                    }
                    else
                    {
                        actualSize++;
                        push(matryoshka, doll);
                    }
                }
            }
            else if (doll > 0 && i == 0)
            {
                isMatryoshka = 0;
                break;
            }
            else
            {
                lastElement = topValue(matryoshka);
                if (abs(lastElement) == doll)
                {
                    pop(matryoshka);
                    actualSize--;
                }
                else
                {
                    isMatryoshka = 0;
                    break;
                }
            }
        }
        if (dollSize)
        {

            if (isMatryoshka == 1)
            {
                printf(":-) Matriosca!\n");
            }
            else
            {
                printf(":-( Tente novamente.\n");
            }
        }
        free(matryoshka->stackArray);
        free(matryoshka);
    }
    return 0;
}