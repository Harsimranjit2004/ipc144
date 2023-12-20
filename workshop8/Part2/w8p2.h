/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : hsdosanjh1234@gmail.com
Student ID#: 155452220
Email      : hsingh956@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// ----------------------------------------------------------------------------
#ifndef CATFOODINFO_H
#define CATFOODINFO_H

#define max_p_analyze 3
#define gm_suggested 64
#define POUNDS_IN_KG 2.20462

struct CatFoodInfo
{
    int p_sku;
    double p_price;
    int p_cal;
    double p_weight;
};

struct ReportData
{
    int p_id;
    double p_price;
    int p_cal;
    double p_lbs;
    double p_kg;
    int p_gram;
    double t_serving;
    double serving_cost;
    double cal_serving;
};
int getIntPositive(int *num);

double getDoublePositive(double *d_check);

void openingMessage(const int n_products);

struct CatFoodInfo getCatFoodInfo(const int num_products);

void displayCatFoodHeader(void);

void displayCatFoodData(int p_sku, double *p_price, int p_cal, double *p_weight);

void start(void);

double convertLbsKg(const double *pounds, double *res_kg);

int convertLbsG(const double *pounds, int *res_gram);

void convertLbs(const double *pounds, double *res_kg, int *res_gram);

double calculateServings(const int serving_size, const int total_grams, double *no_serving);

double calculateCostPerServing(const double *price, const double *t_servings, double *serving_cost);

double calculateCostPerCal(const double *price, const double *t_cal, double *cost_cal);

struct ReportData calculateReportData(struct CatFoodInfo cat);

void displayReportHeader(void);

void displayReportData(const struct ReportData cat, int cheapest);

void displayFinalAnalysis(const struct CatFoodInfo cheap);

#endif // CATFOODINFO_H