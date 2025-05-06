#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "cs50.h"

int main(void)
{
    // Prompt the user for input
    string input = get_string("Enter a number: ");
    if (input == NULL)
    {
        printf("Failed to get input.\n");
        return 1;
    }

    // Use get_long to validate the input
    long value = get_long("%s", input);

    // Check if get_long returned LONG_MAX, indicating invalid input
    if (value == LONG_MAX)
    {
        printf("Invalid input: %s\n", input);
        free(input); // Free the string allocated by get_string
        return 1;
    }

    // Print both the raw string and the validated long value
    printf("You entered: %s (as long: %ld)\n", input, value);

    // Free the string allocated by get_string
    free(input);

    return 0;
}