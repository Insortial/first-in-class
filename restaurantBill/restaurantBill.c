//Program intended on finding the tax and tip values of a given meal after the user types it into the command line
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () 
{
    int i;
    float food[4] = {9.95, 4.55, 13.25, 22.35};
    float tax;
    float tip;
    float total;
    time_t t;

    srand((unsigned) time(&t));
    i = rand() % 4;
    printf("Your meal will be chosen from these 4\nSalad: $9.55\nSoup: $4.55\nSandwich: $13.25\nPizza: $22.35\n");
    printf("Enter tax percentage: ");
    scanf("%f", &tax);
    printf("Enter tip percentage: ");
    scanf("%f", &tip);
    tax *= food[i] * .01;
    tip *= food[i] * .01;
    total = food[i] + tax + tip;
    printf("Cost of meal: $%.2f\n", round(food[i] * 100)/100);
    printf("Your tax: $%.2f\n", round(tax * 100)/100);
    printf("Your tip: $%.2f\n", round(tip * 100)/100);
    printf("Your total: $%.2f\n", round(total * 100)/100);
    return 0;
}