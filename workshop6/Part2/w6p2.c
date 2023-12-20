/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define MAX_WISH 10
int main()
{
    const double minIncome = 500.00, maxIncome = 400000.00, minPrice = 100.00;
    double Income, total = 0;
    int flag = 1, wish_list, orderBy, c_priority;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");
    while (flag)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &Income);
        if (Income < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (Income > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        else
        {
            flag = 0;
        }
        printf("\n");
    }
    flag = 1;
    while (flag)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wish_list);
        if (wish_list <= 0 || wish_list > MAX_WISH)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else
        {
            flag = 0;
        }
        // printf("\n");
    }
    double cost[MAX_WISH];
    int priority[MAX_WISH];
    char finance[MAX_WISH];
    flag = 1;
    int i;

    for (i = 1; i <= wish_list; i++)
    {
        printf("\n");
        flag = 1;
        double temp_cost;
        int temp_priority;
        char temp_finance;
        printf("Item-%d Details:\n", i);
        while (flag)
        {
            printf("   Item cost: $");
            scanf("%lf", &temp_cost);
            if (temp_cost >= minPrice)
            {
                cost[i - 1] = temp_cost;
                flag = 0;
            }
            else
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }
        flag = 1;
        while (flag)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &temp_priority);
            if (temp_priority == 1 || temp_priority == 2 || temp_priority == 3)
            {
                priority[i - 1] = temp_priority;
                flag = 0;
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }
        flag = 1;
        while (flag)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &temp_finance);
            if (temp_finance == 'y' || temp_finance == 'n')
            {
                finance[i - 1] = temp_finance;
                flag = 0;
            }
            else
            {
                printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
            }
        }
    }
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 1; i <= wish_list; i++)
    {
        total = total + cost[i - 1];
        printf("%3d  %5d    %5c    %11.2lf\n", i, priority[i - 1], finance[i - 1], cost[i - 1]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", total);

    flag = 1;
    while (flag)
    {
        printf("\n");
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &orderBy);
        // printf("\n");
        if (orderBy == 0)
        {
            flag = 0;
        }
        else if (orderBy == 1)
        {
            int total_months, months, years;
            total_months = total / Income;
            years = total_months / 12;
            months = total_months % 12;
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", total);
            printf("Forecast: %d years, %d months\n", years, months + 1);
            int financed;
            for ( i = 0; i < wish_list; i++)
            {
                if (finance[i] == 'y')
                {
                    financed = 1;
                }
            }
            if (financed == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (orderBy == 2)
        {
            total = 0;
            printf("\n");
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &c_priority);
            printf("\n");
            int financed = 0;
            for ( i = 0; i < wish_list; i++)
            {
                if (priority[i] == c_priority)
                {
                    total = total + cost[i];
                    if (finance[i] == 'y')
                    {
                        financed = 1;
                    }
                }
            }
            int total_months, months, years;
            total_months = total / Income;
            years = total_months / 12;
            months = total_months % 12;
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", c_priority);
            printf("Amount:   $%.2lf\n", total);
            printf("Forecast: %d years, %d months\n", years, months + 1);

            if (financed == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else
        {
            printf("\n");
            printf("ERROR: Invalid menu selection.\n");
        }
    }
    printf("\n");
    printf("Best of luck in all your future endeavours!\n\n");
    return 0;
}