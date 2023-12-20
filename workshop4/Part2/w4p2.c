/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  :Harsimranjit singh
Student ID#:155452220
Email      :hsingh956@myseneca.ca
Section    :NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <stdio.h>
void print_shopping()
{
    printf("Grocery Shopping\n");
    printf("================\n");
    int apples, oranges, pears, tomatoes, cabbages;
    while (1)
    {
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        if (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        if (apples >= 0)
        {
            break;
        }
    }
    // oranges
    printf("\n");
    while (1)
    {
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        if (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        if (oranges >= 0)
        {
            break;
        }
    }
    printf("\n");
    while (1)
    {
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        if (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        if (pears >= 0)
        {
            break;
        }
    }
    printf("\n");
    while (1)
    {
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        if (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        if (tomatoes >= 0)
        {
            break;
        }
    }
    printf("\n");
    while (1)
    {
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        if (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        if (cabbages >= 0)
        {
            break;
        }
    }
    printf("\n");
    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    if (apples)
    {
        int temp = apples, sum = 0;
        while (1)
        {
            int c_apples;
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &c_apples);
            sum = sum + c_apples;
            if (sum <= 0)
            {
                sum = 0;
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (sum == temp)
            {
                printf("Great, that's the apples done!\n\n");
                break;
            }
            if (sum > temp)
            {
                sum = sum - c_apples;
                printf("You picked too many... only %d more APPLE(S) are needed.\n", temp - sum);
                continue;
            }
            if (sum < temp)
            {
                printf("Looks like we still need some APPLES...\n");
                continue;
            }
        }
    }
    // ############################################ ORANGES

    if (oranges)
    {
        int temp = oranges, sum = 0;
        while (1)
        {
            int c_oranges;
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &c_oranges);
            sum = sum + c_oranges;
            if (sum <= 0)
            {
                sum = 0;
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (sum == temp)
            {
                printf("Great, that's the oranges done!\n\n");
                break;
            }
            if (sum > temp)
            {
                sum = sum - c_oranges;
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", temp - sum);
                continue;
            }
            if (sum < temp)
            {
                printf("Looks like we still need some ORANGES...\n");
                continue;
            }
        }
    }
    // ########################################pears

    if (pears)
    {
        int temp = pears, sum = 0;
        while (1)
        {
            int c_pears;
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &c_pears);
            sum = sum + c_pears;
            if (sum <= 0)
            {
                sum = 0;
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (sum == temp)
            {
                printf("Great, that's the pears done!\n\n");
                break;
            }
            if (sum > temp)
            {
                sum = sum - c_pears;
                printf("You picked too many... only %d more PEAR(S) are needed.\n", temp - sum);
                continue;
            }
            if (sum < temp)
            {
                printf("Looks like we still need some PEARS...\n");
                continue;
            }
        }
    }
    // ############################################## TOMATOS
    if (tomatoes)
    {
        int temp = tomatoes, sum = 0;
        while (1)
        {
            int c_tomatoes;
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &c_tomatoes);
            sum = sum + c_tomatoes;
            if (sum <= 0)
            {
                sum = 0;
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (sum == temp)
            {
                printf("Great, that's the tomatoes done!\n\n");
                break;
            }
            if (sum > temp)
            {
                sum = sum - c_tomatoes;
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", temp - sum);
                continue;
            }
            if (sum < temp)
            {
                printf("Looks like we still need some TOMATOES...\n");
                continue;
            }
        }
    }
    // ####################CABBAGE
    if (cabbages)
    {
        int temp = cabbages, sum = 0;
        while (1)
        {
            int c_cabbages;
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &c_cabbages);
            sum = sum + c_cabbages;
            if (sum <= 0)
            {
                sum = 0;
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (sum == temp)
            {
                printf("Great, that's the cabbages done!\n\n");
                break;
            }
            if (sum > temp)
            {
                sum = sum - c_cabbages;
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", temp - sum);
                continue;
            }
            if (sum < temp)
            {
                printf("Looks like we still need some CABBAGES...\n");
                continue;
            }
        }
    }
}
int main(void)
{

    print_shopping();
    printf("All the items are picked!\n\n");
    while (1)
    {
        int exit;
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &exit);
        printf("\n");
        // printf("%d", exit);
        if (exit == 0)
        {
            break;
        }
        else
        {
            print_shopping();
	    printf("All the items are picked!\n\n");
        }
    }

    printf("Your tasks are done for today - enjoy your free time!\n\n");
    printf("\n");
    return 0;
}
