#include <stdio.h>

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("x: %d\n", x);
    printf("x^1: %d\n", x);
    printf("x^2: %d\n", power(x, 2));
    printf("x^3: %d\n", power(x, 3));
    printf("x^4: %d\n", power(x, 4));
    printf("x^5: %d\n", power(x, 5));
    return 0;
}