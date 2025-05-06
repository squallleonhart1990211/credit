#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cs50.h>

#define true 1
#define false 0

// Prompt for input.
// Calculate checksum.
// Check for card length and starting digits
// Print AMEX, MASTERCARD, or INVALID

int isValidLength(long ccn);
int luhn(string ccs);

int main(void)
{
    string credit_card_string;
    long credit_card_number;
    
    do
    {
        credit_card_number = get_long("Number: ");
        
    } while (!isValidLength(credit_card_number));
    

    // DEBUG BEGIN
    // credit_card_string = "4111111111111111";
    // credit_card_string = "4012888888881881";
    // credit_card_string ="83";

    sprintf(credit_card_string, "%ld", credit_card_number); // Convert long to string
    printf("credit_card_string: %s", credit_card_string);
    int luhn_ccs = luhn(credit_card_string);
    printf("38\tluhn(credit_card_string): %i\n", luhn_ccs); // DEBUG
    if (!luhn_ccs)
    {
        printf("INVALID\n");
        return 0;
    }

    if ((credit_card_string[0] - '0') == 4)
    {
        printf("VISA\n");
        return 0;
    }

    printf("TODO\n"); // TODO
}


int isValidLength(long ccn)
{
    
    int ndigits = 0; // number of digits in credit card number
   
    if (ccn < 10)
    {
        return false; // early return
    }


    while (ccn > 0)
    {
        ccn /= 10;
        ndigits++;
    }
    
    if (ndigits > 16)
    {
        return false;
    }
    
    return true;
}

int luhn(string ccs)
{
    int strlen_css = strlen(ccs);
    if (strlen_css < 0)
    {
        return false;
    }

    int checksum = 0;
    for (int i = (strlen_css - 1); i >= 0; i--)
    {
        int j = (strlen_css - 1) - i; // j tracks the index from right to left
        
        if (j % 2 == 1) // check parity of j
        {
            int rule3 = ((ccs[i] - '0') * 2) % 9;
            // printf("117\trule3: %i\n", rule3);
            checksum += rule3;
        }
        else
        {
            checksum += (ccs[i] - '0');
        }
    }
    printf("107\tchecksum: %i\n", checksum); // DEBUG
    return checksum%10 == 0;
}