// load libraries: stdio and cs50
#include <stdio.h>
#include <cs50.h>

void hash_hash(int nh, int ns);

int main(void)
{
    // initialize variable height
    int height;
    // do while loop
    do
    {
        // prompt user for height
        height = get_int("Height: ");
    }
    // repeat while height is not between 1 and 8 inclusive
    while (height < 1 || height > 8);
    
    for (int i = 0; i < height; i++)
    {
        hash_hash(i + 1, height - (i + 1));
        printf("\n");
    }
}



void hash_hash(int nh, int ns)
{
    // print space ns times
    for (int i = 0; i < ns; i++)
    {
        printf(" ");
    }
    // print hash (#) nh times
    for (int i = 0; i < nh; i++)
    {
        
        printf("#");
    }
    // print double space
    printf("  ");
    // print hash (#) nh times
    for (int i = 0; i < nh; i++)
    {
        
        printf("#");
    }
}