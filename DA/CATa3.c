#include <stdio.h>
#include <string.h>

int main() {
    char password[] = "aeiceg"; 
    char input[3][3]; 
    char diagonal[6]; 
    
    
    printf("Enter 9 characters as 3x3 matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf(" %c", &input[i][j]);
        }
    }
    
    
    for(int i=0; i<3; i++) {
        diagonal[i] = input[i][i];
    }
    
    
    for(int i=0; i<3; i++) {
        diagonal[i+3] = input[i][2-i];
    }
    
    
    diagonal[6] = '\0';
    
    
    if(strcmp(diagonal, password) == 0) {
        printf("Password accepted. Locker opened.\n");
    } else {
        printf("Incorrect password. Try again.\n");
    }
    
    return 0;
}