/**
 * v9 is the last version using get_char. 
 * 
 * This is a sensible approach for the traversal of the string, but makes validating that all chars are digits, 
 * i.e. that the string represents an actual number 
 * more complicated, besides deviating from the intended purpose of the exercise which is to work with
 * longs. 
 * 
 * So for v10 I'm starting from scratch with get_long. 
 */

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

int countDigits(long ccn);
int isValidLength(long ccn);
int luhn_v1(string ccs);
int luhn(string ccs);

int main(void)
{
    string credit_card_string;
    long credit_card_number;
    /*
    do
    {
        credit_card_string = get_string("Number: ");
        // printf("!(isValid): %i\n", !(isValid(credit_card_number)));
        char *tail;
        credit_card_number = strtol(credit_card_string, &tail, 10);

        printf("\tcredit_card_number: %ld\t", credit_card_number); // DEBUG
        printf("\t!(isValidLength): %i\n", !(isValidLength(credit_card_number))); // DEBUG

    } while (!isValidLength(credit_card_number));
    */

    // DEBUG BEGIN
    // credit_card_string = "4111111111111111";
    // credit_card_string = "4012888888881881";
    credit_card_string = "42";

    char *tail;
    credit_card_number = strtol(credit_card_string, &tail, 10);
    printf("Number: %ld\n", credit_card_number);                                // DEBUG
    printf("44\t!(isValidLength): %i\n", !(isValidLength(credit_card_number))); // DEBUG
    // DEBUG END

    int digits = countDigits(credit_card_number);

    printf("49\tdigits= %i\n", digits);              // DEBUG
    printf("50\tNumber= %li\n", credit_card_number); // DEBUG
    // printf("51\tluhn(credit_card_string): %i\n", luhn(credit_card_string)); // DEBUG

    if (!luhn(credit_card_string))
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

int countDigits(long ccn)
{
    int ndigits = 0; // number of digits in credit card number
    while (ccn > 0)
    {
        ccn /= 10;
        ndigits++;
    }
    return ndigits;
}

int isValidLength(long ccn)
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
    int strlen_css = strlen(ccs);
    if (strlen_css < 0)
    {
        return false;
    }

    int checksum = 0;
    for (int i = strlen_css - 1; i >= 0; i--)
    {
        int j = strlen_css - 1 - i; // j tracks the index from right to left
        printf("127\ti: %i\t", i);
        printf("128\tj: %i\t", j);
        printf("129\tccs[%i]: %c\n", i, ccs[i]);

        if (j % 2 == 1) // check parity of j
        {
            int rule3 = ((ccs[i] - '0') * 2) % 9;
            printf("134\trule3: %i\n", rule3);
            checksum += rule3;
        }
        else
        {
            checksum += (ccs[i] - '0');
        }
    }
    printf("139\tchecksum: %i\n", checksum); // DEBUG
    return true;
}