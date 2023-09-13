#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculateSumArray(int squareRoot, int numberOfElements, int *vectorOfElements,
                       int *vectorOfSums)
{
    int sum = 0;
    int index = 0;
    int check = squareRoot;

    for (int i = 0; i < numberOfElements; i++)
    {
        sum += vectorOfElements[i];

        if (i == (check - 1) || i + 1 == numberOfElements)
        {
            vectorOfSums[index] = sum;
            sum = 0;
            index++;
            check = check + (squareRoot);
        }
    }
}

int main()
{

    int numberOfElements;
    int *vectorOfElements;
    int squareRoot;
    int *vectorOfSums;
    int element = 0;

    scanf("%d", &numberOfElements);

    vectorOfElements = (int *)malloc(sizeof(int) * numberOfElements);
    squareRoot = (int)ceil(sqrt(numberOfElements));
    vectorOfSums = (int *)malloc(sizeof(int) * (squareRoot));

    for (int i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &element);
        vectorOfElements[i] = element;
    }

    calculateSumArray(squareRoot, numberOfElements, vectorOfElements,
                      vectorOfSums);

    char command;
    int startOrIndex, stopOrValue;
    int totalSum;
    int remainder;
    int haltCase;

    while (scanf(" %c%d%d", &command, &startOrIndex, &stopOrValue) == 3)
    {
        if (command == 'a')
        {
            vectorOfElements[startOrIndex] = stopOrValue;
            calculateSumArray(squareRoot, numberOfElements, vectorOfElements,
                              vectorOfSums);
        }
        else if (command == 's')
        {
            totalSum = 0;
            for (int i = startOrIndex; i <= stopOrValue; i++)
            {
                remainder = i % squareRoot;
                haltCase = i + squareRoot - 1;
                if (remainder == 0 && (haltCase < stopOrValue || stopOrValue == numberOfElements - 1))
                {
                    totalSum += vectorOfSums[i / squareRoot];
                    i = i + squareRoot - 1;
                }
                else
                {
                    totalSum += vectorOfElements[i];
                }
            }

            printf("%d\n", totalSum);
        }
        else
        {
            break;
        }
    }

    free(vectorOfElements);
    free(vectorOfSums);
    return 0;
}