#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, words = 1, vowels = 0, consonants = 0, spaces = 0, special = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i])) // Check for spaces
            spaces++;
        else if (ispunct(str[i])) // Check for special characters
            special++;
        else if (isalpha(str[i])) // Check for vowels and consonants
        {
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    for (i = 0; i < strlen(str) - 1; i++) // Check for words
    {
        if (isspace(str[i]) && !isspace(str[i + 1]))
            words++;
    }

    printf("\nWords = %d\n", words);
    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    printf("Spaces = %d\n", spaces);
    printf("Special Characters = %d\n", special);

    return 0;
}