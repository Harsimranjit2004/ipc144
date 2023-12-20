/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main()
{
    const int JAN = 1, DEC = 12;
    int input_year, input_month;
    printf("General Well-being Log\n");
    printf("======================\n");
    int flag = 1;
    while (flag)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &input_year, &input_month);
        if ((input_year <= MAX_YEAR && input_year >= MIN_YEAR) && input_month <= 12 && input_month >= 1)
        {
            printf("\n");
            printf("*** Log date set! ***\n");
            printf("\n");
            if (input_month == 1)
            {
                flag = 0;
                printf("Log starting date: %d-JAN-%02d\n", input_year, 01);
            }
            if (input_month == 2)
            {
                flag = 0;
                printf("Log starting date: %d-FEB-%02d\n", input_year, 01);
            }
            if (input_month == 3)
            {
                flag = 0;
                printf("Log starting date: %d-MAR-%02d\n", input_year, 01);
            }
            if (input_month == 4)
            {
                flag = 0;
                printf("Log starting date: %d-APR-%02d\n", input_year, 01);
            }
            if (input_month == 5)
            {
                flag = 0;
                printf("Log starting date: %d-MAY-%02d\n", input_year, 01);
            }
            if (input_month == 6)
            {
                flag = 0;
                printf("Log starting date: %d-JUN-%02d\n", input_year, 01);
            }
            if (input_month == 7)
            {
                flag = 0;
                printf("Log starting date: %d-JUL-%02d\n", input_year, 01);
            }
            if (input_month == 8)
            {
                flag = 0;
                printf("Log starting date: %d-AUG-%02d\n", input_year, 01);
            }
            if (input_month == 9)
            {
                flag = 0;
                printf("Log starting date: %d-SEP-%02d\n", input_year, 01);
            }
            if (input_month == 10)
            {
                flag = 0;
                printf("Log starting date: %d-OCT-%02d\n", input_year, 01);
            }
            if (input_month == 11)
            {
                flag = 0;
                printf("Log starting date: %d-NOV-%02d\n", input_year, 01);
            }
            if (input_month == 12)
            {
                flag = 0;
                printf("Log starting date: %d-DEC-%02d\n", input_year, 01);
            }
        }
        if (input_year > MAX_YEAR || input_year < MIN_YEAR)
        {

            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (input_month < JAN || input_month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    }
    return 0;
}
