#include <stdio.h>

int main() {
    int chennai[7], gangtok[7], delhi[7], haveri[7];
    int i;

    printf("Enter the temperature in Chennai for each day of the week:\n");
    for(i=0; i<7; i++) {
        scanf("%d", &chennai[i]);
        if(chennai[i] < 28 || chennai[i] > 33) {
            printf("Invalid input! Chennai temperature should be between 28C and 33C.\n");
            return 0;
        }
    }

    for(i=0; i<7; i++) {
        delhi[i] = chennai[i] - 8;
        haveri[i] = chennai[i] + 5;
    }

    for(i=0; i<7; i++) {
        gangtok[i] = haveri[i] - delhi[i];
    }

    printf("Temperature for Gangtok:\n");
    for(i=0; i<7; i++) {
        printf("%d\n", gangtok[i]);
    }

    return 0;
}