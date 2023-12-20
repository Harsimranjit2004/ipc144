/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Harsimranjit singh
Student ID#: 155452220
Email      : hsdosanjh1234@gmail.com
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int *num)
{
    int temp;
    do
    {
        scanf("%d", &temp);
        if (temp <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (temp <= 0);
    if (num != NULL)
    {

        *num = temp;
    }
    return temp;
}
double getDoublePositive(double *value)
{
    double temp;
    do
    {
        scanf("%lf", &temp);
        if (temp <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (temp <= 0);
    if (value != NULL)
    {

        *value = temp;
    }
    return temp;
}
void openingMessage(const int n_products)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", n_products);
    printf("NOTE: A 'serving' is %dg\n", gm_suggested);
    printf("\n");
}
struct CatFoodInfo getCatFoodInfo(const int item)
{
    struct CatFoodInfo catInfo = {0};
    printf("Cat Food Product #%d\n", item + 1);

    printf("--------------------\n");
    printf("SKU           : ");

    getIntPositive(&catInfo.p_sku);
    printf("PRICE         : $");
    catInfo.p_price = getDoublePositive(NULL);
    printf("WEIGHT (LBS)  : ");

    catInfo.p_weight = getDoublePositive(NULL);
    printf("CALORIES/SERV.: ");
    getIntPositive(&catInfo.p_cal);
    return catInfo;
}
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int p_sku, double *p_price, int p_cal, double *p_weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", p_sku, *p_price, *p_weight, p_cal);
}

// 7. Logic entry point
void start()
{
    int i;
    struct CatFoodInfo cats[max_p_analyze] = {{0}};

    openingMessage(max_p_analyze);
    for (i = 0; i < max_p_analyze; i++)
    {
        cats[i] = getCatFoodInfo(i);
        printf("\n");
    }
    displayCatFoodHeader();
    for (i = 0; i < max_p_analyze; i++)
    {
        struct CatFoodInfo temp = cats[i];
        displayCatFoodData(temp.p_sku, &temp.p_price, temp.p_cal, &temp.p_weight);
    }
    printf("\n\n");
}
