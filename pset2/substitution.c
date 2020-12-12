// load libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 1. check if input is valid expression_______________________________________
    
    // initialize key variable
    string key; 
    
    // if no input argument is provided or more than 1 input arguments are provided
    // IF STATEMENT
    if (argc != 2)
    {
        printf("error: expected single input argument\n");
        return 1;
    }
    int key_length = strlen(argv[1]);
    key = argv[1];
    
    // CLOSE IF STATEMENT
    
    // if length of input is not 26
    //IF STATEMENT
    if (key_length != 26)
    {
        printf("error: expected input string 26 characters long\n");
        return 1;
    }
    // CLOSE IF STATEMENT
    
    // if input contains non alphabetic characters
    // initialize boolean expressions
    bool alphabetic_lowercase;
    bool alphabetic_capital;
    bool is_alphabetic;
    
    // FOR LOOP
    for (int i = 0; i < key_length; i++)
    {
        alphabetic_lowercase = key[i] >= 97 && key[i] <= 122;
        alphabetic_capital = key[i] >= 65 && key[i] <= 90;
        is_alphabetic = alphabetic_lowercase || alphabetic_capital;
        // IF STATEMENT
        if (!is_alphabetic)
        {
            printf("error: expected inputs must contain only alphabetic characters\n");
            return 1;
        }
        // CLOSE IF STATEMENT
        
    }
    // CLOSE FOR LOOP
    
    // if some letters are not contained only once in input
    // loop through elements of key
    // FOR LOOP 1
    for (int i = 0; i < key_length; i++)
    {
        // loop through elements of key
        // FOR LOOP 2
        for (int j = 0; j < key_length; j++)
        {
            // if two elements are the same, print error
            // IF STATEMENT
            if (key[i] == key[j] && i != j)
            {
                printf("error: expected input contains each letter only once\n");
                return 1;
            }
            // CLOSE IF STATEMENT
            
        }
        // CLOSE FOR LOOP 2
        
    }
    // CLOSE FOR LOOP 1
    
    // 2. generate lowercase and capital keys______________________________________
    
    char key_lowercase[26];
    char key_capital[26];;
    
    // loop through the elements of key
    // FOR LOOP
    for (int i = 0; i < 26; i++)
    {
        // if element of key is a capital letter
        // IF STATEMENT
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            key_capital[i] = key[i];
            key_lowercase[i] = key_capital[i] + 32;
        }
        // if element of key is lowercase
        else
        {
            key_lowercase[i] = key[i];
            key_capital[i] = key[i] - 32;
        }
        // CLOSE IF STATEMENT
        
    }
    // CLOSE FOR LOOP
    
    // 3. generate ciphertext______________________________________________________
    
    // initialize alphabet string
    char alphabet_lowercase[26];
    char alphabet_capital[26];
    
    // generate alphabet strings
    // FOR LOOP
    for (int i = 0; i < 26; i++)
    {
        alphabet_lowercase[i] = 97 + i;
        alphabet_capital[i] = 65 + i;
    }
    int alphabet_length = 26;
    // CLOSE FOR LOOP
    
    // initialize plaintext
    string plaintext;
    
    // prompt user for plaintext
    plaintext = get_string("plaintext:  ");
    int plaintext_length = strlen(plaintext);
    
    // initialize ciphertext
    char ciphertext[plaintext_length];
    
    // loop through plaintext
    // FOR LOOP 1
    for (int i = 0; i < plaintext_length; i++)
    {
        // if plaintext letter is lowercase
        // IF STATEMENT 1
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            // loop through lowercase alphabet
            // FOR LOOP 2
            for (int j = 0; j < 26; j++)
            {
                // if plaintext letter is equal to lowercase alphabet letter
                // IF STATEMENT 2
                if (plaintext[i] == alphabet_lowercase[j])
                {
                    // ciphertext letter is equal to lowercase key letter with same index as lowercase alphabet letter
                    ciphertext[i] = key_lowercase[j];
                }
                // CLOSE IF STATEMENT 2
                
            }
            // CLOSE FOR LOOP 2
            
        }
        // if plaintext letter is capital
        // ELSE IF STATEMENT 1
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            // loop through capital alphabet
            // FOR LOOP 2
            for (int j = 0; j < 26; j++)
            {
                // if plaintext letter is equal to capital alphabet letter
                // IF STATEMENT 2
                if (plaintext[i] == alphabet_capital[j])
                {
                    // ciphertext letter is equal to capital key letter with same index as capital alphabet letter
                    ciphertext[i] = key_capital[j];
                }
                // CLOSE IF STATEMENT 2
                
            }
            // CLOSE FOR LOOP 2
            
        }
        // CLOSE ELSE IF STATEMENT 1
        
        // if plaintext letter is not alphabetic character
        // ELSE STATEMENT 1
        else
        {
            // ciphertext letter is equal to plaintext letter
            ciphertext[i] = plaintext[i];
        }
        
    }
    // CLOSE FOR LOOP 1
    
    printf("ciphertext: ");
    for (int i = 0; i < plaintext_length; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}