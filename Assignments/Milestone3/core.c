
// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
// #include "a1ms1.c"

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
            printf("ERROR! Value must be between %d and %d inclusive: ",lower,upper);
        }
    }
    return n;
}



char inputCharOption(const char *validCharacters)
{
   char input;
   char newLine = 'x';
   int flag = 1;
   int i, found = 0;
   do{
        scanf(" %c%c",&input,&newLine);
        if(newLine == '\n'){
            for(i =0; validCharacters[i] != '\0';i++){
                if(input == validCharacters[i]){

                flag = 0;
                found = 1;
                }
            }
            if(found){
                // clearInputBuffer();
            }
            if(!found){
                // clearInputBuffer();
                printf("ERROR: Character must be one of [%s]: ", validCharacters);
            }
        }
        // clearInputBuffer();
   }while(flag);
   
   return input;
 
}

void inputCString(char *string, int min_length, int max_lenght)
{
    int length = 0;

    int flag = 1;

    while (flag)
    {
        length = 0;
        scanf("%[^\n]s", string);

        // while (string[length] != '\0')
        // {
        //     length++;
        // }
        length = strlen(string);
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
void inputCStringNumbers(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';
	clearInputBuffer();
    while (flag) {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else {
            flag = 0;
        }
    }
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


