#include <stdio.h>
#include <ctype.h>

int main()
{
    char type_of_the_car[20];
    float price_of_the_car, extra_fitting_price, total, discount, gst, net;

    printf("Enter the type of the car (Hatchback, Sedan, SUV, MUV): ");
    scanf("%s", type_of_the_car);

    printf("Enter the price of the car: ");
    scanf("%f", &price_of_the_car);

    printf("Enter the extra fitting price: ");
    scanf("%f", &extra_fitting_price);

    total = price_of_the_car + extra_fitting_price;

    if (strcmp(type_of_the_car, "Hatchback") == 0) {
        discount = total * 0.03;
    } else if (strcmp(type_of_the_car, "Sedan") == 0) {
        discount = total * 0.05;
    } else if (strcmp(type_of_the_car, "SUV") == 0) {
        discount = total * 0.1;
    } else if (strcmp(type_of_the_car, "MUV") == 0) {
        discount = total * 0.15;
    } else {
        printf("Invalid Type\n");
        return 0;
    }

    gst = (total - discount) * 0.12;
    net = total - discount + gst;

    printf("Net amount to be paid: %.2f\n", net);

    return 0;
}