#include <stdio.h>

void factorialSum(int n, double* sum) {
    if (n == 0) return;
    factorialSum(n-1, sum);
    *sum += (double) 1/n;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    double sum = 0;
    factorialSum(n, &sum);
    printf("Sum of the series is: %lf", sum);
    return 0;
}