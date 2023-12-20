/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Harsimranjit singh
Student ID#: 155452220
Email      : hsingh956@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INT_MAX 2147483647
#include <stdio.h>
#include "w8p2.h"

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
    struct CatFoodInfo catInfo;
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

double convertLbsKg(const double *pounds, double *res_kg)
{
    double kg;
    kg = *pounds / POUNDS_IN_KG;
    if (res_kg != NULL)
    {
        *res_kg = kg;
    }
    return kg;
}
int convertLbsG(const double *pounds, int *res_gram)
{
    int gram;
    gram = (*pounds / POUNDS_IN_KG) * 1000;
    if (res_gram != NULL)
    {
        *res_gram = gram;
    }
    return gram;
}

void convertLbs(const double *pounds, double *res_kg, int *res_gram)
{
    double kg;
    int gram;
    kg = *pounds / POUNDS_IN_KG;
    gram = (*pounds / POUNDS_IN_KG) * 1000;
    if (res_kg != NULL)
    {
        *res_kg = kg;
    }
    if (res_gram != NULL)
    {

        *res_gram = gram;
    }
}
double calculateServings(const int serving_size, const int total_grams, double *no_serving)
{
    double serving;
    serving = (double)total_grams / (double)serving_size;
    if (no_serving != NULL)
    {

        *no_serving = serving;
    }
    return serving;
}

double calculateCostPerServing(const double *price, const double *t_servings, double *serving_cost)
{
    double cost;
    cost = (*price) / (*t_servings);
    if (serving_cost != NULL)
    {
        *serving_cost = cost;
    }
    return cost;
}
double calculateCostPerCal(const double *price, const double *t_cal, double *cost_cal)
{
    double cost;
    cost = (*price) / (*t_cal);

    if (cost_cal != NULL)
    {
        *cost_cal = cost;
    }
    return cost;
}
struct ReportData calculateReportData(struct CatFoodInfo cat)
{
    struct ReportData temp;
    temp.p_id = cat.p_sku;
    temp.p_price = cat.p_price;
    temp.p_cal = cat.p_cal;
    temp.p_lbs = cat.p_weight;
    convertLbsKg(&cat.p_weight, &temp.p_kg);
    convertLbsG(&cat.p_weight, &temp.p_gram);
    calculateServings(gm_suggested, temp.p_gram, &temp.t_serving);
    calculateCostPerServing(&temp.p_price, &temp.t_serving, &temp.serving_cost);
    double total_cal = temp.p_cal * temp.t_serving;
    calculateCostPerCal(&temp.p_price, &total_cal, &temp.cal_serving);
    return temp;
}
void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", gm_suggested);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}
void displayReportData(const struct ReportData cat, int cheapest)
{
    if (cat.p_id == cheapest)
    {

        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", cat.p_id, cat.p_price, cat.p_lbs, cat.p_kg, cat.p_gram, cat.p_cal, cat.t_serving, cat.serving_cost, cat.cal_serving);
    }
    else
    {

        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", cat.p_id, cat.p_price, cat.p_lbs, cat.p_kg, cat.p_gram, cat.p_cal, cat.t_serving, cat.serving_cost, cat.cal_serving);
    }
}
void displayFinalAnalysis(const struct CatFoodInfo cheap)
{
    printf("\n");
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%4.2lf\n\n", cheap.p_sku, cheap.p_price);
    printf("Happy shopping!\n\n");
}
// 7. Logic entry point
void start()
{
    int i;
    int cheap_index;
    struct CatFoodInfo cats[max_p_analyze];
    struct ReportData report[max_p_analyze];
    struct CatFoodInfo cheap;
    double cheap_serving = _CRT_INT_MAX;

    openingMessage(max_p_analyze);
    for (i = 0; i < max_p_analyze; i++)
    {

        cats[i] = getCatFoodInfo(i);
        report[i] = calculateReportData(cats[i]);
        if (report[i].serving_cost < cheap_serving)
        {
            cheap_serving = report[i].serving_cost;
        }
        printf("\n");
    }
    for (i = 0; i < max_p_analyze; i++)
    {
        if (report[i].serving_cost == cheap_serving)
        {
            cheap = cats[i];
            cheap_index = report[i].p_id;
        }
    }
    displayCatFoodHeader();
    for (i = 0; i < max_p_analyze; i++)
    {
        struct CatFoodInfo temp = cats[i];
        displayCatFoodData(temp.p_sku, &temp.p_price, temp.p_cal, &temp.p_weight);
    }
    printf("\n");
    displayReportHeader();
    for (i = 0; i < max_p_analyze; i++)
    {
        struct ReportData temp = report[i];
        displayReportData(temp, cheap_index);
    }

    displayFinalAnalysis(cheap);
}
