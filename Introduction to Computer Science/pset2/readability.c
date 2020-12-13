// load libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // prompt user for text
    string text = get_string("Text: ");
    // length of input string
    int n = strlen(text);
    
    // initialize space, punctuation and signs count variables
    int spaces = 0;
    int punct = 0;
    int signs = 0;
    
    // loop through letter of text
    for (int i = 0; i < n; i++)
    {
        bool sign_condition_1 = text[i] >= 34 && text[i] <= 45;
        bool sign_condition_2 = text[i] == 47;
        bool sign_condition_3 = text[i] >= 58 && text[i] <= 62;
        bool sign_condition_4 = text[i] == 64;
        bool sign_condition_5 = text[i] >= 91 && text[i] <= 96;
        bool sign_condition_6 = text[i] >= 123 && text[i] <= 127;
        bool sign_condition = sign_condition_1 || sign_condition_2 || sign_condition_3 || sign_condition_4 ||
                              sign_condition_5 || sign_condition_6;
        // if you find space, increment variable spaces
        if (text[i] == 32)
        {
            spaces++;
        }
        // if you find period, exclamation point or question mark, increment variable punct
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            punct++;
        }
        else if (sign_condition)
        {
            signs++;
        }
    }
    // number of letters
    int letters = n - spaces - punct - signs;
    // number of words
    int words = spaces + 1;
    // number of sentences
    int sentences = punct;
    
    // number of letters per 100 words
    float L = (float) letters * 100 / (float) words;
    // number of sentences per 100 words
    float S = (float) sentences * 100 / (float) words;
    
    // Coleman-Liau index
    int CL_index = round(0.0588 * L - 0.296 * S - 15.8);
    if (CL_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (CL_index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", CL_index);
    }
}