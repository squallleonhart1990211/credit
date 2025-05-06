#include <stdio.h>
#include <stdlib.h>

#include <cs50.h>

#define true 1
#define false 0


int countDigits(long ccn);
int isValid(long ccn);
int luhn(string credit_card_string);

int main(void)
{
    string credit_card_string;
    long credit_card_number;
    do
    {
        credit_card_string = get_string("Number: ");
        // printf("!(isValid): %i\n", !(isValid(credit_card_number)));
        char *tail;
        credit_card_number = strtol(credit_card_string, &tail, 10);
        printf("credit_card_number: %ld\t", credit_card_number);
        printf("!(isValid): %i\n", !(isValid(credit_card_number)));
        
    } while (!isValid(credit_card_number));
    
    int digits = countDigits(credit_card_number);

    printf("digits= %i\n", digits); // DEBUG
    printf("Number= %li\n", credit_card_number); // DEBUG

    if(!luhn(credit_card_string))
    {
        printf("INVALID");
    }
    else
    {
        printf("VISA"); // TODO
    }

}

int countDigits(long ccn)
{
    int ndigits = 0; // number of digits in credit card number
    while (ccn > 0)
    {
        ccn /= 10;
        //printf("ccn: %li\t", ccn);
        ndigits ++;
        // printf("ndigits: %i\n", ndigits); // DEBUG
    }
    // printf("ndigits: %i\n", ndigits);   
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

int luhn(string credit_card_string)
{
    return false;
}