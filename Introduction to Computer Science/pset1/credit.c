// load libraries
#include <stdio.h>
#include <cs50.h>

// define tuple structure
struct Tuple 
{
    int first, second, third, st_sum;
};

// SUBROUTINES
long int raise_power(int base, int power);
int sum_digits(int n);
struct Tuple luhn_valid(long int N);
//

// MAIN FUNCTION
int main(void)
{
    // prompt user for credit card number
    long int cc_number = get_long("Number: ");
    
    // call luhn's algorithm function to check validity
    struct Tuple valid_check = luhn_valid(cc_number);
    int status = valid_check.st_sum;
    
    // define boolean variables for number of digits and Luhn's algorithm status number
    bool invalid_number_digits = cc_number < 1000000000000 || cc_number > 9999999999999999;
    bool invalid_luhn_status = status % 10 != 0;
    
    // check validity based on number of digits and Luhn's algorithm status number
    // IF STATEMENT
    if (invalid_number_digits || invalid_luhn_status)
    {
        printf("INVALID\n");
        return 0;
    }
    // CLOSE IF STATEMENT
    
    // define boolean variables for first digit
    bool first_zero = valid_check.first == 0;
    bool first_four = valid_check.first == 4;
    bool first_five = valid_check.first == 5;
    // define boolean variables for second digit
    bool second_AMEX = valid_check.second == 3;
    bool second_VISA = valid_check.second == 4;
    bool second_MASTER = valid_check.second == 1 || valid_check.second == 2 || valid_check.second == 3 || 
                         valid_check.second == 4 || valid_check.second == 5;
    // define boolean variable for third digit
    bool third_AMEX = valid_check.third == 4 || valid_check.third == 7;
    
    // check for type of credit card
    // IF STATEMENT
    if (first_zero && second_AMEX && third_AMEX)
    {
        printf("AMEX\n");
    }
    else if ((first_zero && second_VISA) || first_four)
    {
        printf("VISA\n");
    }
    else if (first_five & second_MASTER)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
}
// CLOSE MAIN FUNCTION



// SUBROUTINES

// raise-to-power function
long int raise_power(int base, int power)
{
    // initialize result
    long int result = base;
    // if power is 0 result is 1
    if (power <= 0)
    {
        result = 1;
    }
    else
    {
        while (power != 1)
        {
            result *= base;
            --power;
        }
    }
    return result;
}
//

// sum-of-digits function
int sum_digits(int n)
{
    // initialize sum of digits
    int sum_d;
    // if input is less than 10
    if (n < 10)
    {
        sum_d = n;
    }
    // if input is more than 10
    else if (n > 10)
    {
        sum_d = 1 + n % 10;
    }
    // if input is ten
    else 
    {
        sum_d = 1;
    }
    return sum_d;
}
//

// Luhn's algorithm function
struct Tuple luhn_valid(long int N)
{
    // initialize return status number
    int n;
    // initialize powers of 10 variables
    long int ten_i000;
    long int ten_i00;
    long int ten_i0;
    long int ten_i;
    // initialize digit variables
    long int d00 = 0;
    long int d0 = 0;
    long int d1 = 0;
    long int d2 = 0;
    // initialize sum of digits variables
    int sum1 = 0;
    int sum2 = 0;
    
    // initialize counter
    int i = 0;
    // assign value to variable so the while loop can commence
    ten_i = 2;
    
    // WHILE LOOP
    // while remainder of N/10^i is not equal to N
    while (N % ten_i != N)
    {
        // increment counter by 2
        i += 2;
        // powers of 10
        ten_i000 = raise_power(10, i - 3);
        ten_i00 = raise_power(10, i - 2);
        ten_i0 = raise_power(10, i - 1);
        ten_i = raise_power(10, i);
        // calculate remainders of divisions of input with powers of 10
        d00 = N % ten_i000;
        d0 = N % ten_i00;
        d1 = N % ten_i0;
        d2 = N % ten_i;
        
        // calculate current digit d2 (i)
        // IF STATEMENT
        if (d2 < ten_i0)
        {
            d2 = 0;
        }
        else
        {
            d2 = (d2 - d1) / ten_i0;
        }
        // CLOSE IF STATEMENT
        
        // calculate previous digit d1 (i - 1)
        // IF STATEMENT
        if (d1 < ten_i00)
        {
            d1 = 0;
        }
        else
        {
            d1 = (d1 - d0) / ten_i00;
        }
        // CLOSE IF STATEMENT
        
        // calculate 2 digits back d0 (i - 2)
        // IF STATEMENT
        if (d0 < ten_i000)
        {
            d0 = 0;
        }
        else
        {
            d0 = (d0 - d00) / ten_i000;
        }
        // CLOSE IF STATEMENT
        
        // increment sum2 by the sum of the digits of the current digit (i) multiplied by 2
        sum2 += sum_digits(2 * d2);
        // increment sum1 by the previous digit (i - 1)
        sum1 += d1;
    }
    // CLOSE WHILE LOOP
    
    // add sums
    n = sum1 + sum2;
    
    struct Tuple out = { d2, d1, d0, n };
    return out;
}
//