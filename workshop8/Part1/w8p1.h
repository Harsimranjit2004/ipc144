
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

#ifndef CATFOODINFO_H
#define CATFOODINFO_H

#define max_p_analyze 3
#define gm_suggested 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int p_sku;
    double p_price;
    int p_cal;
    double p_weight;
};
// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *num);
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *d_check);
// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int n_products);
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int num_products);
// 5. Display the formatted table header
void displayCatFoodHeader(void);
// 6. Display a formatted record of cat food data
void displayCatFoodData(int p_sku, double *p_price, int p_cal, double *p_weight);
// 7. Logic entry point
void start(void);

#endif // CATFOODINFO_H