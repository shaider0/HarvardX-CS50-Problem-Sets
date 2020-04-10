// Problem: Prompt user to provide a block of text. Calculate the number of letters per 100 words. Calculate the number of sentences per 100 words. Apply those values to the Coleman-Liau index formula to calculate the reading level for the block of text.

// include libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// declare your functions (which will be initialized with values later)
float countLetters(string text);
float countWords(string text);
float countSentences(string text);
float clindex(float letterCount, float wordCount, float sentenceCount);

int main(void)
{
    // prompt user for string, store it in a variable called text
    string text = get_string("Text: ");


    // pass text to the countLetters function, store the return value in letterCount
    float letterCount = countLetters(text);

    // pass text to the countLetters function, store the return value in wordCount
    float wordCount = countWords(text);

    // pass text to the countSentences function, store the return value in sentenceCount
    float sentenceCount = countSentences(text);

    // pass letterCount, wordCount, and sentenceCount to the clindex functions, store the return value in gradeLevel
    float gradeLevel = clindex(letterCount, wordCount, sentenceCount);

    // print "Before Grade 1" for all cl index valus < 1
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }

    // print "16+" for all cl index values > or = 16
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }

    // print the grade level, rounded to the nearest integer
    else
    {
        printf("Grade %.0f\n", round(gradeLevel));
    }
}


// initialize countLetters function which takes as an argument a string of sentences
float countLetters(string text)

{

    float letterCount = 0;

    // loop over all the characters in the string

    for (int i = 0; i < strlen(text); i++)
    {
        // using ascii chart, increment the lettercount for each letter (exclude spaces and special characters)
        if (text[i] >= 65 && text[i] <= 90)
        {
            letterCount++;
        }

        if (text[i] >= 97 && text[i] <= 122)
        {
            letterCount++;
        }
    }
    return letterCount;
}


// initialize a countWords function which takes as an argument a string of sentences
float countWords(string text)
{
    float wordCount = 0;

    // loop over all the characters in the string
    for (int i = 0; i < strlen(text); i++)
    {
        // whenever you encounter an empty space, increment wordCount
        if (text[i] == ' ')
        {
            wordCount++;
        }
        // whenever you encounter a !, . , or ?, increment wordCount and skip the next character (increment i)
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            wordCount++;
            i++;
        }
    }

    return wordCount;
}

float countSentences(string text)
// initialize a countSentences function which takes as an argument a string of sentences
{
    float sentenceCount = 0;

// loop over all the characters in the string
    for (int i = 0; i < strlen(text); i++)
    {
        // whenever you encounter a !, . , or ?, increment sentenceCount
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentenceCount++;
        }
    }

    return sentenceCount;
}

// initialize clindex function which takes letterCount, wordCount, and sentenceCount as arguments

float clindex(float letterCount, float wordCount, float sentenceCount)

{
    // calculate l, which is the number of letters per 100 words
    float l = (100 * letterCount) / wordCount;


    // calculate s, which is the number of sentences per 100 words
    float s = (100 * sentenceCount) / wordCount;

    // calculate the Coleman-Liau index using the provided formula
    return (0.0588 * l) - (0.296 * s) - 15.8;
}
