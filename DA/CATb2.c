#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];
    int i, len, upper=0, lower=0, digit=0, space=0, special=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        if(isupper(str[i]))
            upper++;
        else if(islower(str[i]))
            lower++;
        else if(isdigit(str[i]))
            digit++;
        else if(isspace(str[i]))
            space++;
        else
            special++;
    }
    printf("\nUppercase Alphabets: %d", upper);
    printf("\nLowercase Alphabets: %d", lower);
    printf("\nDigits: %d", digit);
    printf("\nWhite Spaces: %d", space);
    printf("\nSpecial Symbols: %d", special);
    return 0;
}