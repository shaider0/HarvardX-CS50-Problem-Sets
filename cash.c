// Problem: Ask user to input a dollar amount representing the amount of change to be returned. Print the minimum number of coins it would take to provide change.

// include libraries
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// call main function with no params
int main(void)
{
    // declare float variable called dollars, initially with garbage value
    float dollars;
    // use do while loop to prompt user for change amount, repeating each time user inputs a non-float or negative value
    do
    {
        dollars = get_float("How much change?");
    }
    while (dollars < 0);

    // convert user input to cents
    int cents = round(dollars * 100);
    int solution = 0;

    // as long as the number in cents is greater than the coin denomination, subtract that denomination and add 1 to the solution counter. proceed top-to bottom from quarters to dimes to nickels to pennies

    while (cents >= 25)
    {
        cents = cents - 25;
        solution++;
    }

    while (cents >= 10)
    {
        cents = cents - 10;
        solution++;
    }

    while (cents >= 5)
    {
        cents = cents - 5;
        solution++;
    }

    while (cents >= 1)
    {
        cents = cents - 1;
        solution++;
    }

    // print the solution
    printf("%i\n", solution);
}
