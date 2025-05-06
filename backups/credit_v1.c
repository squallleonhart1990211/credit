#include <stdio.h>

#include <cs50.h>

#define true 1
#define false 0

int countDigits(long ccn);
int isValid(long ccn);
int main(void)
{
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Number: ");
        // printf("!(isValid): %i\n", !(isValid(credit_card_number)));
    } while (!isValid(credit_card_number));
    
    int digits = countDigits(credit_card_number);

    printf("digits= %i\n", digits);
    printf("Number= %li\n", credit_card_number);
}

int countDigits(long ccn)
{
    int ndigits; // number of digits in credit card number
    while (ccn > 0)
    {
        ccn /= 10;
        //printf("ccn: %li\t", ccn);
        ndigits ++;
        //printf("ndigits: %i\n", ndigits);
    }   
    return ndigits;
}

int isValid(long ccn)
{
    if (ccn < 0)
    {
        return false;
    }
    else if (countDigits(ccn) > 16)
    {
        return false;
    }
    else
    {
        return true;
    }
}
