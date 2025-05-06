#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        printf("\tcredit_card_number: %ld\t", credit_card_number); // DEBUG
        printf("\t!(isValid): %i\n", !(isValid(credit_card_number))); // DEBUG
        
    } while (!isValid(credit_card_number));
    
    int digits = countDigits(credit_card_number);

    printf("\tdigits= %i\n", digits); // DEBUG
    printf("\tNumber= %li\n", credit_card_number); // DEBUG

    if(!luhn(credit_card_string))
    {
        printf("INVALID\n");
    }
    else
    {
        if((credit_card_string[0]-'0') == 4) 
        {
            printf("VISA\n"); 
        }
        else
        {
            printf("TODO\n"); // TODO
        }
    }



}

int countDigits(long ccn)
{
    int ndigits = 0; // number of digits in credit card number
    while (ccn > 0)
    {
        ccn /= 10;
        ndigits ++;
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

int luhn(string ccs)
{
   if (strlen(ccs) < 0)
   {
    return false;
   }

    // Get the last character (validator digit)
    char validator_digit = ccs[strlen(ccs) - 1]; // MOCK
    printf("\tvalidator_digit: %c\n", validator_digit); // DEBUG

    // Mock validation: Check if the last digit is '0'
    if(validator_digit != '0') // MOCK
    {
        return false;
    }

    return true;
}