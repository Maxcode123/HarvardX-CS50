// load libraries: stdio and cs50
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt user for name
    string name = get_string("What's your name?");
    // print message
    printf("hello, %s\n", name);
}