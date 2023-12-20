
// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Harsimranjit singh
Student ID#: 155452220
Email      : hsingh956@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include "core.h"
//#include "a1ms1.c"

void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    int n;
    char newline = 'x';

    while (newline != '\n')
    {
        scanf("%d%c", &n, &newline);

        if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return n;
}
int inputIntPositive(void)
{
    int n;
    char newline = 'x';
    int flag = 1; // declaring the flag for breaking the loop
    while (flag)
    {
        scanf("%d%c", &n, &newline);
        if (newline == '\n' && n >= 0)
        {
            flag = 0;
        }
        else if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number : ");
        }
        else
        {
            printf("ERROR! Value must be > 0: ");
        }
    }
    return n;
}
int inputIntRange(int lower, int upper)
{
    int n;
    char newline = 'x';
    int flag = 1; // declaring the flag for breaking the loop
    while (flag)
    {
        scanf("%d%c", &n, &newline);
        if (newline == '\n' && (n >= lower && n <= upper))
        {
            flag = 0;
        }
        else if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else
        {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    }
    return n;
}

char inputCharOption(const char *validCharacters)
{
    int size_string = 0;
    char character;
    int flag = 1;
    int i;
    int isvalid = 0;

    while (validCharacters[size_string] != '\0')
    {
        size_string++;
    }

    while (flag)
    {
        scanf(" %c", &character);
        for (i = 0; i < size_string; i++)
        {
            if (validCharacters[i] == character)
            {

                isvalid = 1;
            }
        }
        if (isvalid)
        {
            flag = 0;
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ", validCharacters);
        }
    }
    clearInputBuffer();
    return character;
}

void inputCString(char *string, int min_length, int max_lenght)
{
    int length = 0;
   
    int flag = 1;

    while (flag)
    {
        length = 0;
        scanf("%[^\n]s", string);

        while (string[length] != '\0')
        {
            length++;
        }
        if (length >= min_length && length <= max_lenght)
        {
            flag = 0;
        }
        else
        {
            clearInputBuffer();
            if (min_length == max_lenght)
            {
                printf("ERROR: String length must be exactly %d chars: ", min_length);
            }
            else if (length > max_lenght)
            {
                printf("ERROR: String length must be no more than %d chars: ", max_lenght);
            }
            else

            {
                printf("ERROR: String length must be between %d and %d chars: ", min_length, max_lenght);
            }
        }
    }
    clearInputBuffer();
}
void displayFormattedPhone(const char *phone_number)
{
    if (phone_number == NULL)
    {
        printf("(___)___-____");
        return;
    }

    int is_all_digits = 1;
    int length = 0;
    int i;
    while (phone_number[length] != '\0')
    {
        length++;
    }
    for (i = 0; phone_number[i] != '\0'; i++)
    {
        if (phone_number[i] < 48 || phone_number[i] > 57)
        {
            is_all_digits = 0;
        }
    }
    if (is_all_digits && length == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
        {
            printf("%c", phone_number[i]);
        }
        printf(")");
        for (i = 3; i < 6; i++)
        {
            printf("%c", phone_number[i]);
        }
        printf("-");
        for (i = 6; i < 10; i++)
        {
            printf("%c", phone_number[i]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}
