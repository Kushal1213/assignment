#include <stdio.h>

int sumOfDigits(int num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(){
    int sum = 0;
    for(int i = 1000; i <= 9998; i += 2){
        sum += i;
    }
    int finalSum = sumOfDigits(sum);
    while(finalSum > 9){
        finalSum = sumOfDigits(finalSum);
    }
    if(finalSum % 2 == 0){
        printf("Even found");
    }
    else{
        printf("Odd found");
    }
    return 0;
}