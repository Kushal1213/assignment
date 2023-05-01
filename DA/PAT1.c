#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    int i;
    for(i=2; i<=sqrt(num); i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int isArmstrong(int num) {
    int sum=0, temp=num, digit;
    while(temp > 0) {
        digit = temp%10;
        sum += pow(digit, 3);
        temp /= 10;
    }
    if(sum == num) {
        return 1;
    }
    else {
        return 0;
    }
}

int isPerfect(int num) {
    int i, sum=0;
    for(i=1; i<num; i++) {
        if(num%i == 0) {
            sum += i;
        }
    }
    if(sum == num) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(isPrime(num)) {
        printf("%d is prime number\n", num);
    }
    else {
        printf("%d is not a prime number\n", num);
    }
    
    if(isArmstrong(num)) {
        printf("%d is a armstrong number\n", num);
    }
    else {
        printf("%d is not a armstrong number\n", num);
    }
    
    if(isPerfect(num)) {
        printf("%d is a perfect number\n", num);
    }
    else {
        printf("%d is not a perfect number\n", num);
    }
    
    return 0;
}