// Problem: Ask user to input a height and print the corresponding pyramid made of hash symbols

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for height, store it in a variable called height
    // use a do while loop to ask at least once, and continue prompting user until  they provide a number between 1 and 8 inclusive
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);

    // keep track of the number of empty spaces before the # symbols. To start, it is height - 1.
    int spaces = height - 1;

    // use a for loop to build multiple rows
    for (int i=0; i<height; i++)
    {
        // use a for loop to build each row
        for(int j=0; j<spaces; j++)
        {
            printf(" ");
        }

        for(int y=0; y<height-spaces; y++)
        {
            printf("#");
        }
        // decrement spaces variable and move to new line
        spaces--;
        printf("\n");
    }
}
