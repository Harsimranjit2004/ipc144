/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3

int main()
{
    const int JAN = 1, DEC = 12;
    char M1, M2, M3;
    int input_year, input_month, day = 1;
    double MorningR, EveningR, MorningTotal = 0, EveningTotal = 0, Overall, avgMorning, avgEvening, avgOverall;
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

            if (input_month == 1)
            {
                flag = 0;
                M1 = 'J';
                M2 = 'A';
                M3 = 'N';
            }
            if (input_month == 2)
            {
                M1 = 'F';
                M2 = 'E';
                M3 = 'B';
                flag = 0;
            }
            if (input_month == 3)
            {
                M1 = 'M';
                M2 = 'A';
                M3 = 'R';
                flag = 0;
            }
            if (input_month == 4)
            {
                M1 = 'A';
                M2 = 'P';
                M3 = 'R';
                flag = 0;
            }
            if (input_month == 5)
            {
                M1 = 'M';
                M2 = 'A';
                M3 = 'Y';
                flag = 0;
            }
            if (input_month == 6)
            {
                M1 = 'J';
                M2 = 'U';
                M3 = 'N';
                flag = 0;
            }
            if (input_month == 7)
            {
                M1 = 'J';
                M2 = 'U';
                M3 = 'L';
                flag = 0;
            }
            if (input_month == 8)
            {
                M1 = 'A';
                M2 = 'U';
                M3 = 'G';
                flag = 0;
            }
            if (input_month == 9)
            {
                M1 = 'S';
                M2 = 'E';
                M3 = 'P';
                flag = 0;
            }
            if (input_month == 10)
            {
                M1 = 'O';
                M2 = 'C';
                M3 = 'T';
                flag = 0;
            }
            if (input_month == 11)
            {
                M1 = 'N';
                M2 = 'O';
                M3 = 'V';
                flag = 0;
            }
            if (input_month == 12)
            {
                M1 = 'D';
                M2 = 'E';
                M3 = 'C';
                flag = 0;
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
    int i;
    for ( i = 1; i <= LOG_DAYS; i++)
    {
        printf("\n");
        printf("%d-%c%c%c-%02d\n", input_year, M1, M2, M3, day);
        int flag = 1;
        while (flag)
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &MorningR);
            if (MorningR >= 0.0 && MorningR <= 5.0)
            {
                MorningTotal = MorningTotal + MorningR;
                flag = 0;
            }
            else
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        flag = 1;
        while (flag)
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &EveningR);
            if (EveningR >= 0.0 && EveningR <= 5.0)
            {
                EveningTotal = EveningTotal + EveningR;
                flag = 0;
            }
            else
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        day++;
    }
    printf("\n");
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %2.3lf\n", MorningTotal);
    printf("Evening total rating:  %4.3lf\n", EveningTotal);
    printf("----------------------------\n");
    Overall = MorningTotal + EveningTotal;
    printf("Overall total rating: %2.3lf\n", Overall);
    printf("\n");
    avgMorning = MorningTotal / LOG_DAYS;
    printf("Average morning rating:  %.1lf\n", avgMorning);
    avgEvening = EveningTotal / LOG_DAYS;
    printf("Average evening rating:  %.1lf\n", avgEvening);
    printf("----------------------------\n");
    avgOverall = (avgEvening + avgMorning) / 2;
    printf("Average overall rating:  %.1lf\n", avgOverall);
    return 0;
}
