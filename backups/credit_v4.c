#include <stdio.h>
#include <stdlib.h>

#include <cs50.h>

#define true 1
#define false 0


int countDigits(long ccn);
int isValid(long ccn);
int luhn(string ccs);

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

    if(luhn(credit_card_string))
    {
        if((credit_card_string[0]-'0') == 4) 
        {
            printf("VISA\n"); // TODO
        }
        else
        {
            printf("TODO\n");
        }
    }
    else
    {
        printf("INVALID\n");
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

int luhn(string ccs)
{
   if (strlen(ccs) < 0)
   {
    return false;
   }
   else
   {
    char validator_digit = ccs[strlen(ccs) - 1];
    printf("validator_digit: %c", validator_digit);
    if(validator_digit != '0')
    {
        return false;
    }
    else
    {
        return true;
    }
   }
}