#include <stdio.h>
#include <string.h>
#include <ctype.h>

int processString(char *input) {
    char firstWord[20];
    char secondWord[20];
    int i = 0, j = 0, len = 0;

    // Extracting the first and second words from the input string
    sscanf(input, "%s %s", firstWord, secondWord);

    // Converting the first word to title case
    firstWord[0] = toupper(firstWord[0]);
    for (i = 1; firstWord[i] != '\0'; i++) {
        firstWord[i] = tolower(firstWord[i]);
    }

    // Converting the second word to uppercase
    for (j = 0; secondWord[j] != '\0'; j++) {
        secondWord[j] = toupper(secondWord[j]);
    }

    // Printing the revised string and its length
    printf("%s %s\n", firstWord, secondWord);
    len = strlen(input);
    printf("%d\n", len);

    // Returning the length or size of the string
    if (len < 20) {
        return len;
    } else {
        return sizeof(input);
    }
}

int main() {
    char inputString[50];

    // Reading the input string from the user
    printf("Enter a sentence with two words: ");
    fgets(inputString, 50, stdin);

    // Removing the newline character from the input string
    inputString[strcspn(inputString, "\n")] = 0;

    // Calling the function to process the input string
    int result = processString(inputString);

    printf("Result: %d", result);

    return 0;
}