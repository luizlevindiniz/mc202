#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ManisEnemytoVirginity

int numberOfPalindromes(char *substring, int length)
{
    char midLetter = '$';
    int palindromesInAWord = 0;

    for (int i = 0; i < (length - 2); i++)
    {

        if (tolower(substring[i]) == tolower(substring[i + 2]))
        {
            if (midLetter == '$')
            {
                palindromesInAWord++;
                midLetter = substring[i + 1];
            }
            else
            {
                if (substring[i + 1] != midLetter && substring[i + 1] != ' ')
                {
                    palindromesInAWord++;
                    midLetter = substring[i + 1];
                }
            }
        }

        if (i > 0 && tolower(substring[i]) == tolower(substring[i + 1]))
        {
            if (tolower(substring[i - 1]) == tolower(substring[i + 2]))
            {
                palindromesInAWord++;
            }
        }
    }

    return palindromesInAWord;
}

int main()
{

    char text[500];
    int len = 0;
    int count = 0;

    while (fgets(text, 500, stdin))
    {

        char *substring = strtok(text, " ");
        while (substring != NULL)
        {
            len = strlen(substring);
            count = numberOfPalindromes(substring, len);
            printf("%s - %d\n", substring, count);
            if (count >= 2)
            {
                printf("%s\n", substring);
            }
            substring = strtok(NULL, " ");
        }
    }

    return 0;
}