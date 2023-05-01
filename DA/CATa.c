#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int length, i, j, freq = 0;
    int repeat_flag = 0, non_repeat_flag = 0;
    char *repeat_ptr, *non_repeat_ptr;
    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);
    printf("Length of the string is: %d\n", length);

    for (i = 0; i < length; i++)
    {
        if (str[i] != ' ')
        {
            freq++;
            for (j = i + 1; j < length; j++)
            {
                if (str[j] == str[i])
                {
                    str[j] = ' ';
                }
            }
        }
    }
    printf("Word frequency is: %d\n", freq);

    for (i = 0; i < length; i++)
    {
        repeat_flag = 0;
        non_repeat_flag = 0;
        for (j = i + 1; j < length; j++)
        {
            if (str[i] == str[j])
            {
                repeat_flag = 1;
                break;
            }
        }
        if (repeat_flag == 1)
        {
            repeat_ptr = &str[i];
            printf("First repeated character is: %c\n", *repeat_ptr);
            break;
        }
    }
    if (repeat_flag == 0)
    {
        printf("No repeated characters found in the string.\n");
    }
    for (i = 0; i < length; i++)
    {
        non_repeat_flag = 0;
        for (j = 0; j < length; j++)
        {
            if (i != j && str[i] == str[j])
            {
                non_repeat_flag = 1;
                break;
            }
        }
        if (non_repeat_flag == 0)
        {
            non_repeat_ptr = &str[i];
            printf("First non-repeated character is: %c\n", *non_repeat_ptr);
            break;
        }
    }
    return 0;
}