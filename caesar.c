// Problem: Implement the caesar cipher. User passes in a key (a non-negative integer) as a command line argument. Then, user is prompted to provide a plaintext string. The program applies the key to the plaintext string and prints the ciphertext.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // If user passes more than 1 command line argument, return 1 and an error message
    if (argc != 2)
    {
        printf("Usage: ./caesar key.\n");
        return 1;
    }

    // store the cipher key in a variable called key. convert that to an int and use the modulo operator to handle values greater than 26
    string key = argv[1];
    int x = atoi(key);
    int y = x % 26;

    // get string from user and store in variable called plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // loop over the plaintext string
    // for each char, add the key, and return the char at that position
    // handle edge cases where the addition of the key goes beyond letters
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] <= 90 && plaintext[i] >= 65)
        {
            if (plaintext[i] + y > 90)
            {
            printf("%c", 64 + ((plaintext[i] + y) - 90));
            }
            else
            {
            printf("%c", plaintext[i] + y);
            }
        }

        else if (plaintext[i] <= 122 && plaintext[i] >= 97)
        {
            if (plaintext[i] + y > 122)
            {
            printf("%c", 96 + ((plaintext[i] + y) - 122));
            }
            else
            {
            printf("%c", plaintext[i] + y);
            }
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
