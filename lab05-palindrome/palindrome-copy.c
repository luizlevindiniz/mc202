#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ManisEnemytoVirginity

void checkPalindrome(char *substring, int lenght, int start, int end)
{
    if (lenght >= 3)
    {

        int isPalindrome = 1;

        for (int i = start, j = 0; j < lenght - 1; j++)
        {
            if (substring[i + j] != substring[end - 1 - j])
            {
                isPalindrome = 0;
                break;
            }
        }

        if (isPalindrome)
        {

            for (int z = start; z < end; z++)
            {
                printf("%c", substring[z]);
            }
            printf("\n");
        }

        lenght = lenght - 1;
        end = end - 1;
        checkPalindrome(substring, lenght, start, end);
        start = start + 1;
        end = end + 1;
        checkPalindrome(substring, lenght, start, end);
        return;
    }

    return;
}

int main()
{

    char text[500];
    int len = 0;

    fgets(text, 500, stdin);

    len = strlen(text);
    checkPalindrome(text, len, 0, len);

    return 0;
}